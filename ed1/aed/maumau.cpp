#include <bits/stdc++.h>

using namespace std;

/* Node class definitions */

// Circular doubly linked list node
template <typename T>
class DoubleNode
{
private:
    T data;
    DoubleNode<T> *next, prev;

public:
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
private:
    T data;
    Node<T> *next;

public:
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

// Tree node
template <typename T>
class TreeNode
{
private:
    TreeNode<T> *left, right, parent;
    T key, data;

public:
    static TreeNode<T> make_node(T k, T d)
    {
        TreeNode<T> *p = new TreeNode<T>;

        if (p)
        {
            p->data = d;
            p->key = k;
            p->left = nullptr;
            p->right = nullptr;
            p->parent = nullptr;
        }

        return p;
    }

    static void destroy_node(TreeNode<T> p)
    {
        delete p;
    }
};
/* end node class definitions */

/* Data structure class definitions */

// Circular doubly linked list
template <typename T>
class CircularDoublyLinkedList
{
private:
    DoubleNode<T>* iterator, head, tail;
    int n;

public:
    CircularDoublyLinkedList()
    {
        head = tail = iterator = nullptr;
    }

    DoubleNode<T> *search(T key)
    {
        iterator = head;

        while (iterator != nullptr && iterator->data != key)
            iterator = iterator->next;

        return iterator;
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
            head = tail = iterator = p;
            n++;
            return true;
        }

        p->next = y->next;
        p->prev = y;

        if (y->next)
            y->next->prev = p;

        y->next = p;
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
            head = tail = iterator = p;
            n++;
            return true;
        }

        p->next = head;
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
            head = tail = iterator = p;
            n++;
            return true;
        }

        tail->next = p;
        p->prev = tail;
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
        DoubleNode<T>::destroy_node(p);
        n--;
        return;
    }

    void pop_front()
    {
        DoubleNode<T> *p = head;
        head = head->next;
        head->prev = nullptr;

        DoubleNode<T>::destroy_node(p);
        return;
    }

    void pop_back()
    {
        DoubleNode<T> *p = tail;

        tail = tail->prev;
        tail->next = nullptr;
        DoubleNode<T>::destroy_node(p);
        return;
    }

    T front() { return head->data; }
    T back() { return tail->data; }

    void clear()
    {
        while (head)
            pop_front();
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

// Binary tree
template <typename T>
class BTree
{
private:
    TreeNode<T> *root;
    int n;

public:
    static void inorder_walk(TreeNode<T> *node)
    {
        if (node->left)
            inorder_walk(node->left);

        cout << node->key << " ";

        if (node->right)
            inorder_walk(node->right);
    }

    static void preorder_walk(TreeNode<T> *node)
    {
        cout << node->key << " ";

        if (node->left)
            preorder_walk(node->left);

        if (node->right)
            preorder_walk(node->right);
    }

    static void postorder_walk(TreeNode<T> *node)
    {
        if (node->left)
            postorder_walk(node->left);

        if (node->right)
            postorder_walk(node->right);

        cout << node->key << " ";
    }

    pair<bool, TreeNode<T> *> search(TreeNode<T> *r, T k)
    {
        if (!r)
        {
            TreeNode<T> *junk;
            return {false, junk};
        }

        if (r->key == k)
            return {true, r};

        if (r->key > k)
            return search(r->left, k);

        return search(r->right, k);
    }

    pair<bool, TreeNode<T> *> iterative_search(TreeNode<T> *r, T k)
    {
        while (r)
        {
            if (r->key == k)
                return {true, r};

            else if (r->key > k)
                r = r->left;

            else
                r = r->right;
        }

        TreeNode<T> *junk;
        return {false, junk};
    }

    TreeNode<T> iterative_tree_min(TreeNode<T> *r)
    {
        while (r->left)
            r = r->left;

        return r->key;
    }

    TreeNode<T> tree_min(TreeNode<T>* r)
    {
        if (!r->left)
            return r;

        return tree_min(r->left);
    }

    TreeNode<T> iterative_tree_max(TreeNode<T> *r)
    {
        while (r->right)
            r = r->right;

        return r;
    }

    TreeNode<T> tree_max(TreeNode<T> *r)
    {
        if (!r->right)
            return r;

        return tree_max(r->right);
    }

    TreeNode<T> successor(TreeNode<T> *r)
    {
        if (r->right)
            return tree_min(r->right);

        TreeNode<T> parent = r->parent;

        while (parent && r == parent->right)
        {
            r = parent;
            parent = parent->parent;
        }

        return parent;
    }

    T predecessor(TreeNode<T> *r)
    {
        if (r->left)
            return tree_max(r->left);

        TreeNode<T> *parent = r->parent;

        while (parent && r == parent->left)
        {
            r = parent;
            parent = parent->parent;
        }

        return parent;
    }

    static bool insert(BTree<T> *t, T k, T dt)
    {
        TreeNode<T> *p = TreeNode<T>::make_node(k, dt);

        if (!p)
            return false;

        TreeNode<T> *r = t->root;
        TreeNode<T> *in = nullptr;
        while (r)
        {
            in = r;

            if (r->key >= p->key)
                r = r->left; 
            else r = r->right;
        }

        p->parent = in;

        if (!in)
            t->root = p;
        else if (p->key <= in->key)
            in->left = p;
        else
            in->right = p;
    }

    void clear_subtree(TreeNode<T> *r)
    {
        if (r->left)
            clear_subtree(r->left);

        else if (r->right)
            clear_subtree(r->right);
        else
            delete r;
    }

    void transplant(TreeNode<T> *u, TreeNode<T> *v)
    {
        if (!u->parent)
            root = v;

        else if (u == u->parent->left)
            u->parent->left = v;

        else if (u == u->parent->right)
            u->parent->right = v;

        if (v)
            v->parent = u->parent;
    }

    void remover(TreeNode<T> *z)
    {
        if (!z->left)
        {
            transplant(z, z->right);
            delete z;
        }

        else if (!z->right)
        {
            transplant(z, z->left);
            delete z;
        }

        else
        {
            TreeNode<T> y = successor(z);

            if (y != z->right)
            {
                transplant(y, y->right);
                y->right = z->right;
            }

            swap(z->key, y->key);
            swap(z->data, y->data);
            remover(z);
        }
    }

    bool remove(T dt)
    {
        pair<bool, TreeNode<T> *> found = search(root, dt);

        if (found)
        {
            remover(found.second);
            return true;
        }

        return false;
    }
};
/* end data structure node definitions */

/* Type definitions*/

typedef CircularDoublyLinkedList<int> dcll; // should not be int, will create class for player

/* end type definitions */
int main()
{

}