#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;

    static Node<T> *build_node(T dt)
    {
        Node<T> *p = new Node<T>;

        if (p)
        {
            p->data = dt;
            p->next = nullptr;
        }

        return p;
    }

    static void destroy_node(Node<T> *p) { delete p; }
};

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
            if (!head)
            {
                head = tail = p;
            }
            else
            {
                tail->next = p;
                tail = p;
            }
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

    void push(T t)
    {
        Node<T> *node = Node<T>::build_node(t);
        node->next = top; // Node pushed points to current top
        top = node;       // Update top to point to new top node
        n++;
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

    T find_node(int n)
    {
        Node<T> *it = top;

        while (n-- && it->next)
        {
            it = it->next;
        }

        return it->data;
    }
};

int main()
{
    // Stores each player's color using stl's map
    map<char, int> cores;

    // Creates the game board using six stacks in an array
    Stack<string> board[6];

    // Stores players' chips using four queues
    Queue<string> fichas[4];

    // Stores the amount of chips in board
    int qtd = 0;

    // Taking input
    int buff = 52;
    while (buff--)
    {
        string j;
        cin >> j;

        cores[j[1]] = j[0] - 48;
        fichas[j[0] - 49].push(string() + j[1] + j[2]);
    }

    // flag to keep game running
    bool run = true;

    // Stores current player
    Queue<char> current;
    current.push('A');
    current.push('V');
    current.push('R');
    current.push('B');

    while (run)
    {
        int jogador = cores[current.front()];
        string ficha = fichas[jogador - 1].front();
        int torre = ficha[1] - 49;
        fichas[jogador - 1].pop();

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
            while (board[nTorre].size() >= 6)
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
    int max = 0, p;
    char mx;
    pair<char, int> winners[4] = {{'A', 0}, {'V', 0}, {'R', 0}, {'B', 0}};
    // Determine winner
    for (int i = 0; i < 6; i++)
    {
        string s = board[i].find_node(i);
        score[cores[s[0]] - 1]++;

        if (score[cores[s[0]] - 1] > max)
        {
            max = score[cores[s[0]] - 1];
            mx = s[0];
            p = cores[s[0]] - 1;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (score[cores[winners[i].first] - 1] == max)
            winners[i].second = 1;
    }

    // Output
    cout << "Vencedores:\n";
    int i;
    for (i = 0; i < 4; i++)
    {
        if (winners[i].second)
        {
            cout << winners[i].first;
            break;
        }
    }
    i++;
    for (; i < 4; i++)
        if (winners[i].second)
            cout << ' ' << winners[i].first;

    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << "Mao do jogador " << i + 1 << ":";
        if (fichas[i].empty())
            cout << " Vazia\n";
        else
        {
            while (!fichas[i].empty())
            {
                cout << ' ' << i + 1 << fichas[i].front();
                fichas[i].pop();
            }
            cout << endl;
        }
    }

    cout << "Tabuleiro final:\n";
    i = 0;
    while (!board[5].empty())
    {
        cout << board[i].ttop()[0];
        board[i].pop();
        i++;
        if (i > 5)
        {
            cout << endl;
            i = 0;
        }
        else
            cout << " ";
    }

    return 0;
}