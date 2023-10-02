#include "node.h"
template<typename T>

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