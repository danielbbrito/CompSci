#include <iostream>
#include <string>
#include <map>

using namespace std;
template<typename T>

class Node {
    public:
        T data;
        Node<T> *next;

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
        Node<T>* head;
        Node<T>* tail;
        int n;

    public:
        Queue()
        {
            head = tail = nullptr;
            n = 0;
        }

        bool push(T data)
        {
            Node<T>* p = Node<T>::build_node(data);

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
            Node<T>* p = head;
            head = head->next;
            Node<T>::destroy_node(p);
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
                Node<T>* p = head;
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

template<typename T>

class Stack {
    private:
        Node<T>* top;
        int n;
    public:

        Stack() {top = nullptr;n = 0;}

        void push(T n)
        {
            Node<T>* node = Node<T>::build_node(n);
            node->next = top; // Node pushed points to current top
            top = node; // Update top to point to new top node
            n += 1;
        }

        bool pop()
        {
            if (top)
            {
                Node<T>* current_top = top; // Stores current top so as not to lose it in memory

                top = top->next; // Update top

                Node<T>::destroy_node(current_top); // Destoy former top
                n--;

                return true;
            }

            return false;
        }

        bool empty() {return !top;}

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

        int size() {return n;}
};


int main()
{
    // Stores each player's color using stl's unordered map
    map<char, int> cores;

    // Creates the game board using six stacks in an array
    Stack<string> board[6];

    // Stores players' chips using four queues
    Queue<string> fichas[4];

    // Stores the amount of chips in board
    int qtd = 0;
    
    // Taking input
    char j, c, t;
    while (cin >> j >> c >> t)
    {
        fichas[j - 49].push(string() + c + t);

        if (cores.find(c) == cores.end() && c != 'P')
            cores[c] = j - 49;
    }

    // flag to keep game running
    bool run = true;

    // Stores current player
    Queue<char> current;
    current.push('A');
    current.push('V');
    current.push('R');
    current.push('P');

    while (run)
    {
        int jogador = cores[current.front()];
        string ficha = fichas[jogador].front();
        int torre = ficha[1] - 49;
        fichas[jogador].pop();
        
        // Handles black chips
        if (ficha[0] == 'P')
        {   
            if (!board[torre].empty())
            {
                board[torre].pop();
                qtd--;
            }
        }
        
        // Handles tower not full
        else if (board[torre].size() < 6)
        {
            board[torre].push(ficha);
            qtd++;
        }

        // Handles full tower
        else
        {
            int nTorre = (torre + 1) % 6;
            while (board[nTorre].size())
                nTorre = (nTorre + 1) % 6; 
            
            board[nTorre].push(ficha);
            qtd++;
        }

        // Update player queue
        current.push(current.front());
        current.pop();
        if (qtd >= 36)
            run = false;
        
    }

    // Stores players' scores
    int score[4] = {0, 0, 0, 0};

    // Determine winner
    for(int i = 0; i < 6; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            board[i].pop();
        }

        char cor = board[i].ttop()[0];

        score[cores[cor] - 1]++;
    }

    int ganha = 0;
    int maior = -1;

    for (int i = 0; i < 4; i++)
    {
        if (score[i] > maior)
        {
            maior = score[i];
            ganha = i + 1;
        }
    }

    cout << "O jogador " << ganha << " venceu!!\n";

    return 0;
}