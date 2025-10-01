#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h> 
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

#define PARENT(i) (i - 1 / 2)
#define LEFT(i)   (2 * i + 1)
#define RIGHT(i)  (2 * i + 2)

struct Coords {
    short la;
    short lo;
    short p;
};

struct CoordHeap {
    short heap_size;
    struct Coords heap[1000]
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

int main()
{
    short i = 10;
    pid_t child;
    int fd;
    struct CoordHeap* list; 
    fd = shm_open("/missiles", O_RDWR | O_CREAT, 0777);

    if (fd == -1)
    {
        printf("Erro ao criar o ambiente compartilhado de memória: %s\n", strerror(errno));
        return 1;
    }

    if (ftruncate(fd, sizeof(struct CoordHeap)) == -1)
    {
        printf("Erro ao criar o ambiente compartilhado de memória: %s\n", strerror(errno));
        return 1;
    }

    list = mmap(0, sizeof(*list), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (list == MAP_FAILED)
    {
        fprintf(stderr, "Erro ao mapear objeto de memória: %s\n", strerror(errno));
    }

    list->topo = -1;
    while (i--)
    {
        child = fork();
        if (child < 0) return 1;

        if (child == 0) break;
    }


    if (child == 0)
    {
        srand(getpid());
        struct Coords strike;
        strike.la = rand() % 101;
        strike.lo = rand() % 101;
        strike.p  = rand() % 101;

        if (list->topo < strike.p)
            list->topo = strike.p;
        
        printf("Strike: %d\n", strike.p);
        return 0;
    }

    return 0;
}