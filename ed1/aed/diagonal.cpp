#include <iostream>
#include <string>

using namespace std;
template<typename T>

class Node {
    private:
        T data;
        Node<T>* next;

    public:
        static Node<T>* build_node(T dt)
        {
            Node<T>* p = new Node<T>;

            if (p)
            {
                p->data = dt;
                p->next = nullptr;
            }

            return p;
        }

        static void destroy_node(Node<T>* p) {delete p;}
};


template<typename T>

class Queue {
    private:
        Node<T>* head, tail;
        int n;

    public:
        Queue()
        {
            head = tail = nullptr;
            n = 0;
        }

        bool push(T data)
        {
            Node<T>* p = Node::build_node(data);

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
            Node<T> p = head;
            head = head->next;
            Node::destroy_node(p);
            n--;
        }

        T front() {return head->data;}

        int size() {return n;}

        bool empty() {return !head;}

        void clear()
        {
            n = 0;

            while (head)
            {
                Node<T> p = head;
                head = head->next;
                Node::destroy_node(p);
            }

            tail = nullptr;
        }

        ~Queue()
        {
            clear();
        }
};

template<typename T>

class Stack {
    private:
        Node<T>* top;
        int n;
    public:

        Stack() {top = nullptr;n++;}

        void push(T n)
        {
            Node<T>* node = Node<T>::build_node(n);
            node->next = *top; // Node pushed points to current top
            top = node; // Update top to point to new top node
            n++;
        }

        void pop()
        {
            if (top)
            {
                Node<T>* current_top = top; // Stores current top so as not to lose it in memory

                top = top->next; // Update top

                Node<T>::destroy_node(current_top); // Destoy former top
                n--
            }
        }

        bool empty() {return !top;}

        void clear()
        {
            while (top)
                pop();
        }

        T top()
        {
            T tp;
            if (top)
                tp = top->data;
            
            return tp;
        }

        int size() {return n;}

        
};

struct Jogador {
    char jogador, cor;
    Queue<char> fichas;
};

int main()
{
    Jogador info[4];
    Stack<string> board[6];
    
    for (int i = 0; i < 4; i++)
    {
        char j, c; cin >> j >> c;
        info[j - 49].cor = c;

        for (int i = 0; i < 11; i++)
        {
            char f;
            cin >> f;
            info[j - 49].fichas.push(f);
        }
    }
}