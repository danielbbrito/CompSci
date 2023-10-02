template<typename T>

class QueueVet {
private:
    int size, head, tail;

    T *v;

public:
    QueueVet(int size) {this->size = size + 1;}

    ~QueueVet() {delete[] v;}

    void push(T el)
    {
        if (head == (tail + 1) % size)
            throw -1;
        
        v[tail] = el;
        tail = (tail + 1) % size;
        return;
    }

    void pop()
    {
        if (head == tail)
            throw -1;
        
        head = (head + 1) % size;
        return;
    }

    bool empty() {return head == tail;}

    bool full() {return head == (tail + 1) % size;}

    T front() {return v[head];}

    void clear() {tail = head;}
};