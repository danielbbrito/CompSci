#include "node.h"
template<typename T>

// Singly linked list
class LinkedList {
    private:
        int n;
        Node<T>* head, tail, it;
    public:

        LinkedList()
        {
            head = tail = it = nullptr;
            n = 0;
        }
        bool push(T dt)
        {
            Node<T>* ptr = Node::build_node(dt);

            if (!ptr) return false;

            if (!head)
            {
                head = tail = it = ptr;
                n++;
                return true;
            }

            ptr->next = it->next;
            it->next = ptr;
            n++;
            return true;
        }

        bool push_back(T dt)
        {
            Node<T>* ptr = Node::build_node(dt);

            if (!ptr) return false;

            if (!head)
            {
                head = tail = it = ptr;
                n++;
                return true;
            }

            tail->next = ptr; // Point to new element
            tail = ptr; // Update tail location
            n++;
            return true;
        }

        bool push_front(T dt)
        {
            Node<T>* ptr = Node::build_node(dt);

            if (!ptr) return false;

            if (!head)
            {
                head = tail = it = ptr;
                n++;
                return true;
            }

            ptr->next = head;
            head = ptr;
            n++;
            return true;
        }

        Node<T>* search(T dt)
        {
            it = head;

            while (it->data != dt)
                it = it->next;

            return it;
        }

        void pop(T dt)
        {// Removes the first occurrence of dt
            Node<T>* ptr = head;

            while (ptr->next->data != dt)
                ptr = ptr->next;
            
            Node<T>* rm = ptr->next;

            ptr->next = ptr->next->next;

            Node::destroy_node(rm);
        }

        void pop_front()
        {
            Node<T> rm = head;
            head = head->next;

            Node::destroy_node(rm);
        }

        void clear()
        {
            while (head)
                pop_front();
        }

        T front()
        {
            return head->data;
        }

        T back()
        {
            return tail->data;
        }
};

// Doubly linked list
template<typename T>
class DoublyLinkedList {
    private:
        DoubleNode<T>* iterator, head, tail;
        int n;

    public:
        DoubleNode<T>* search(T key)
        {
            iterator = head;

            while (iterator != nullptr && iterator->data != key)
                iterator = iterator->next;
            
            return iterator;
        }

        bool push(DoubleNode<T>* y, T dt)
        {
            /**
             * Inserts new node right after y
            */
            DoubleNode<T>* p = DoubleNode::build_node(dt);

            if (!p) return false;

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

           DoubleNode<T>* p = DoubleNode::build_node(dt);

           if (!p) return false;

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

           DoubleNode<T>* p = DoubleNode::build_node(dt);

           if (!p) return false;

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

        void pop(DoubleNode<T>* y, T key)
        {
            if (y)
            {
                y->prev->next = y->next;
                y->next->prev = y->prev;
                DoubleNode::destroy_node(y);
                n--;

                return;
            }

            DoubleNode<T>* p = search(key);

            p->prev->next = p->next;
            p->next->prev = p->prev;
            DoubleNode::destroy_node(p);
            n--;
            return;
        }

        void pop_front()
        {
            DoubleNode<T>* p = head;
            head = head->next;
            head->prev = nullptr;

            DoubleNode::destroy_node(p);
            return;
        }

        void pop_back()
        {
            DoubleNode<T>* p = tail;

            tail = tail->prev;
            tail->next = nullptr;
            DoubleNode::destroy_node(p);
            return;
        }

        T front() {return head->data;}
        T back() {return tail->data;}

        void clear()
        {
            while (head)
                pop_front();
        }
};