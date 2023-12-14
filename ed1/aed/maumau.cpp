#include <bits/stdc++.h>

using namespace std;

/* Node class definitions */

// Circular doubly linked list node
template <typename T>
class DoubleNode
{
public:
    T data;
    DoubleNode<T> *next, *prev;
    static DoubleNode<T> *build_node(T dt)
    {
        DoubleNode<T> *p = new DoubleNode<T>;

        if (p)
        {
            p->data = dt;
            p->next = p->prev = nullptr;
        }

        return p;
    }

    static void destroy_node(DoubleNode<T> *p) { delete p; }
};

// Stack node
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

/* end node class definitions */

/* Data structure class definitions */

// Circular doubly linked list
template <typename T>
class CircularDoublyLinkedList
{
private:
    DoubleNode<T> *it, *head, *tail;
    int n;

public:
    CircularDoublyLinkedList()
    {
        head = tail = it = nullptr;
    }

    DoubleNode<T> *search(T key)
    {
        it = head;

        while (it != nullptr && it->data != key)
            it = it->next;

        return it;
    }

    bool push(DoubleNode<T> *y, T dt)
    {
        /**
         * Inserts new node right after y
         */
        DoubleNode<T> *p = DoubleNode<T>::build_node(dt);

        if (!p)
            return false;

        if (!head)
        {
            head = tail = it = p;
            p->next = head;
            p->prev = tail;
            n++;
            return true;
        }

        p->next = y->next;
        p->next->prev = p;
        y->next = p;
        p->prev = y;
        n++;
        return true;
    }

    bool push_front(T dt)
    {
        /**
         * Inserts new node at the front (head) of the list
         */

        DoubleNode<T> *p = DoubleNode<T>::build_node(dt);

        if (!p)
            return false;

        if (!head)
        {
            head = tail = it = p;
            p->next = p->prev = p;
            n++;
            return true;
        }

        p->next = head;
        p->prev = head->prev;
        p->next->prev = p;
        head->prev = p;
        head = p;
        n++;
        return true;
    }

    bool push_back(T dt)
    {
        /**
         * Inserts new element at the back (tail) of the list
         */

        DoubleNode<T> *p = DoubleNode<T>::build_node(dt);

        if (!p)
            return false;

        if (!head)
        {
            head = tail = it = p;
            p->next = p->prev = p;
            n++;
            return true;
        }

        p->prev = tail;
        p->next = tail->next;
        p->next->prev = p;
        tail->next = p;
        tail = p;

        n++;
        return false;
    }

    void pop(DoubleNode<T> *y, T key)
    {
        if (y)
        {
            y->prev->next = y->next;
            y->next->prev = y->prev;
            DoubleNode<T>::destroy_node(y);
            n--;

            return;
        }

        DoubleNode<T> *p = search(key);

        p->prev->next = p->next;
        p->next->prev = p->prev;
        it = p->next;

        if (p == head)
            head = p->next;

        if (p == tail)
            tail = p->prev;
        DoubleNode<T>::destroy_node(p);
        n--;
        return;
    }

    void pop_front()
    {
        DoubleNode<T> *p = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;

        DoubleNode<T>::destroy_node(p);
        n--;
        return;
    }

    void pop_back()
    {
        DoubleNode<T> *p = tail;

        tail = tail->prev;
        tail->next = head;
        tail->next->prev = tail;
        DoubleNode<T>::destroy_node(p);
        n--;
        return;
    }

    T front() { return head->data; }
    T back() { return tail->data; }
    int size() { return n; }
    void itMM()
    {
        it = it->next;
    }

    void itmm()
    {
        it = it->prev;
    }

    void reset()
    {
        it = head;
    }

    T get()
    {
        return it->data;
    }
    bool empty() { return n == 0; }
    void clear()
    {
        while (!empty())
            pop_back();
    }
};

// Stack
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

    void push(T a)
    {
        Node<T> *node = Node<T>::build_node(a);
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
        T d;
        if (top)
            d = top->data;

        return d;
    }

    int size() { return n; }
};

/* end data structure node definitions */

/* Struct definitions */
struct card
{
    char value, naipe;
    int relative;

    card(char v, char n)
    {
        value = v;
        naipe = n;

        relative = (value - 64) + abs((naipe - 51));
    }
    card() {}
    bool operator==(card b)
    {
        return this->naipe == b.naipe && this->value == b.value;
    }
};

struct com
{
    bool operator()(card a, card b)
    {
        return a.relative < b.relative;
    }
};
/* end struct definitions */

/* Type definitions*/

typedef CircularDoublyLinkedList<int> dcll;

/* end type definitions */

/* Utility functions */
bool compare_cards(card a, card b)
{
    return a.naipe == b.naipe || a.value == b.value;
}

int main()
{
    int n;
    cin >> n;
    vector<card> hands[11];
    Stack<card> monte, lixo;
    dcll game;

    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;

        for (int k = 0; k < j; k++)
        {
            game.push_back(k);
        }

        for (int k = 0; k < 104; k++)
        {
            char valor, naipe;
            cin >> valor >> naipe;
            monte.push(card(valor, naipe));
        }

        // Distribute cards
        for (int k = 0; k < j * 5 && monte.size(); k++)
        {
            for (int l = 0; l < j; l++)
            {
                hands[l].push_back(monte.ttop());
                monte.pop();
            }
        }

        for (int k = 0; k < j; k++)
        {
            sort(hands[k].begin(), hands[k].end(), com());
        }

        bool run = true;

        bool orientation = true; // true = clockwise false = ccw

        while (run)
        {

            bool plays = true;
            if (lixo.empty())
            {
                lixo.push(hands[game.get()].back());
                hands[game.get()].pop_back();
            }

            else
            {
                card atual = lixo.ttop();
                int current_player = game.get();
                bool flag = false;
                for (int k = hands[current_player].size() - 1; k >= 0; k--)
                {
                    if (compare_cards(atual, hands[current_player][k]))
                    {
                        lixo.push(hands[current_player][k]);
                        hands[current_player].erase(hands[current_player].begin() + k);
                        flag = true;
                        break;
                    }
                }

                if (atual == lixo.ttop() && !flag)
                {
                    // Try to play new card
                    if (compare_cards(atual, monte.ttop()))
                    {
                        if (monte.size())
                        {
                            lixo.push(monte.ttop());
                            monte.pop();
                        }
                    }
                    else
                    {
                        if (monte.size())
                        {
                            hands[current_player].push_back(monte.ttop());
                            monte.pop();
                        }

                        sort(hands[current_player].begin(), hands[current_player].end(), com());
                        plays = false;
                    }
                }
            }

            if (plays) // The following only need to run is the player has played a card
            {
                // Check if player still has cards
                if (hands[game.get()].size() == 0)
                {
                    game.pop(nullptr, game.get());
                }

                // Check if change of state is necessary
                if (lixo.ttop().value == 12) // Changes orientation
                {
                    orientation = 0 ? orientation : 1;
                }

                else if (lixo.ttop().value == 1) // Skips next player
                {
                    if (orientation)
                        game.itMM();
                    else
                        game.itmm();
                }

                else if (lixo.ttop().value == 7) // Next player buys two cards
                {
                    game.itMM();
                    for (int l = 0; l < 2; l++)
                    {
                        hands[game.get()].push_back(monte.ttop());
                        monte.pop();
                    }
                    sort(hands[game.get()].begin(), hands[game.get()].end(), com());

                    game.itmm();
                }
                else if (lixo.ttop().value == 9) // Previous player buys three cards
                {
                    game.itmm();
                    for (int l = 0; l < 3; l++)
                    {

                        hands[game.get()].push_back(monte.ttop());
                        monte.pop();
                    }
                    sort(hands[game.get()].begin(), hands[game.get()].end(), com());

                    game.itMM();
                }
            }

            if (game.size() == 1)
                run = false;
            if (orientation)
                game.itMM();
            else
                game.itmm();

            if (monte.empty()) // Checks if played cards need to be emptied
            {
                card atual = lixo.ttop();
                lixo.pop();
                while (!lixo.empty())
                {
                    monte.push(lixo.ttop());
                    lixo.pop();
                }
                lixo.push(atual);
            }
        }

        cout << "Vencedor da partida " << i << " Jogador " << game.front() + 1 << endl;
    }
}
