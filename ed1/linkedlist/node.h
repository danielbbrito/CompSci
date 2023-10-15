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
class DoubleNode{
    private:
        T data;
        DoubleNode<T>* next, prev;

    public:
        static DoubleNode<T>* build_node(T dt)
        {
            DoubleNode<T>* p = new DoubleNode<T>;

            if (p)
            {
                p->data = dt;
                p->next = p->prev = nullptr;
            }

            return p;
        }

        static void destroy_node(DoubleNode<T>* p) {delete p;}
};