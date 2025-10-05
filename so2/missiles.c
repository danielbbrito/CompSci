#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h> 
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

#define PARENT(i) ((i - 1) / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

struct Coords {
    int la;
    int lo;
    int p;
};

struct CoordHeap {
    int busy;
    int heap_size;
    struct Coords heap[1000];
};



void heapify(struct CoordHeap* h, int index)
{
    int l = LEFT(index);
    int r = RIGHT(index);
    int largest;

    if (l < h->heap_size && h->heap[l].p > h->heap[index].p)
    {
        largest = l;
    }
    else
    {
        largest = index;
    }

    if (r < h->heap_size && h->heap[r].p > h->heap[largest].p)
    {
        largest = r;
    }

    if (largest != index)
    {
        struct Coords aux = h->heap[index];
        h->heap[index] = h->heap[largest];
        h->heap[largest] = aux;

        heapify(h, largest);
    }

    return;
}

struct Coords heap_max(struct CoordHeap* h)
{
    if (h->heap_size < 1)
    {
        struct Coords err = {-1, -1, -1};
        return err;
    }

    return h->heap[0];
}

struct Coords heap_pop(struct CoordHeap* h)
{
    struct Coords max = heap_max(h);

    h->heap[0] = h->heap[h->heap_size - 1];

    h->heap_size--;

    heapify(h, 0);

    return max;
}


int heap_insert(struct CoordHeap* h, struct Coords x)
{
    if (h->heap_size == 1000)
    {
        return -1;
    }

    h->heap_size++;

    h->heap[h->heap_size - 1] = x;
    
    int i = h->heap_size - 1;

    while (i > 0 && h->heap[PARENT(i)].p < h->heap[i].p)
    {
        struct Coords aux = h->heap[PARENT(i)];
        h->heap[PARENT(i)] = h->heap[i];
        h->heap[i] = aux;

        i = PARENT(i);
    }

    return 0;
}

void lock_queue(struct CoordHeap* h)
{
    struct timespec ts = {0, 10000 * 1000L};
    while (__sync_lock_test_and_set(&h->busy, 1))
    {
        nanosleep(&ts, NULL);
    }
}

void unlock_queue(struct CoordHeap* h)
{
    __sync_lock_release(&h->busy);
}

int shm_fd_global = -1;
char shm_name[] = "/missiles";
void handle_sigint(int signum) {
    (void)signum;
    if (shm_fd_global != -1) {
        shm_unlink(shm_name);
    }
    _exit(0);
}

int main()
{
    signal(SIGINT, handle_sigint);
    int i = 10;
    pid_t child;
    int fd;
    struct CoordHeap* list;
    fd = shm_open("/missiles", O_RDWR | O_CREAT, 0666);

    if (fd == -1)
    {
        printf("Erro ao criar o ambiente compartilhado de memória: %s\n", strerror(errno));
        return 1;
    }

    shm_fd_global = fd;

    if (ftruncate(fd, sizeof(struct CoordHeap)) == -1)
    {
        printf("Erro ao criar o ambiente compartilhado de memória: %s\n", strerror(errno));
        return 1;
    }

    list = mmap(0, sizeof(*list), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (list == MAP_FAILED)
    {
        printf("Erro ao mapear objeto de memória: %s\n", strerror(errno));
        return 1;
    }

    list->busy = 0;
    list->heap_size = 0;
    memset(list->heap, 0, sizeof(list->heap));

    while (i--)
    {
        child = fork();
        if (child < 0) return 1;

        if (child == 0) break;
    }


    if (child == 0)
    {
        srand((unsigned)getpid());
        while (1)
        {
            struct Coords strike = {rand() % 101, rand() % 101, rand() % 101};

            lock_queue(list);
            
            if (heap_insert(list, strike) == -1 )
            {
                printf("Processo #%d falhou ao enviar coordenadas de ataque (fila cheia)\n\n", getpid());
            }

            printf("Processo #%d inseriu as coordenadas:\n  %d/%d\n  p=%d\n\n", getpid(), strike.la, strike.lo, strike.p);

            unlock_queue(list);

            sleep(1);
        }
        
    }

    if (child > 0)
    {
        while (1)
        {
            lock_queue(list);

            if (list->heap_size > 0)
            {
                struct Coords top = heap_pop(list);
                printf("Ataque realizado em %d/%d com prioridade p=%d. Preparando para novo ataque.\n\n", top.la, top.lo, top.p);
                unlock_queue(list);
            }
            else
            {
                unlock_queue(list);
                struct timespec ts = {0, 100000L}; 
                nanosleep(&ts, NULL);
            }
        }
    }

    return 0;
}