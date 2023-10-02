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