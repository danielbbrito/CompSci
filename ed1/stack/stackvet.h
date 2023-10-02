template<typename T>

class StackVet {
    private:
        int topo = 0; // Keeps track of the next element to be inserted's index
        T *V; // Array to store the stack elements
        int N; // Stack max size
    
    public:
        // Class defined within .h file because apparently class templates cannot be defined in a separate file :)
        StackVet(int n)
        {
            V = new T[n];
            N = n;
        }

        bool empty() {return !topo;}

        void clear() {topo = 0;}

        T top() {return V[topo - 1];}

        bool push(T e)
        {
            if (topo == N) return false;
            V[topo] = e;
            topo++;
            return true;
        }

        bool pop()
        {
            if (topo < 1) return false;

            topo--;
            return true;
        }

        ~StackVet() {delete[] V;}

};