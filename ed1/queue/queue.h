#include "node.h"
template <typename T>

class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int n;

public:
    Queue()
    {
        head = tail = nullptr;
        n = 0;
    }

    bool push(T data)
    {
        Node<T> *p = Node<T>::build_node(data);

        if (p)
        {
            tail->next = p;
            tail = p;
            n++;
            return true;
        }
        return false;
    }

    void pop()
    {
        Node<T> *p = head;
        head = head->next;
        Node<T>::destroy_node(p);
        n--;
    }

    T front() { return head->data; }

    int size() { return n; }

    bool empty() { return !head; }

    void clear()
    {
        n = 0;

        while (head)
        {
            Node<T> *p = head;
            head = head->next;
            Node<T>::destroy_node(p);
        }

        tail = nullptr;
    }

    ~Queue()
    {
        clear();
    }
};
