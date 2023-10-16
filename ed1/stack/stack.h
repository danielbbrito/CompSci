#include "node.h"
template <typename T>

class Stack
{
private:
    Node<T> *top;
    int n;

public:
    Stack()
    {
        top = nullptr;
        n = 0;
    }

    void push(T n)
    {
        Node<T> *node = Node<T>::build_node(n);
        node->next = top; // Node pushed points to current top
        top = node;       // Update top to point to new top node
        n += 1;
    }

    bool pop()
    {
        if (top)
        {
            Node<T> *current_top = top; // Stores current top so as not to lose it in memory

            top = top->next; // Update top

            Node<T>::destroy_node(current_top); // Destoy former top
            n--;

            return true;
        }

        return false;
    }

    bool empty() { return !top; }

    void clear()
    {
        while (top)
            pop();
    }

    T ttop()
    {
        T tp;
        if (top)
            tp = top->data;

        return tp;
    }

    int size() { return n; }
};