template<typename T>

class StackVet {
    private:
        int top = 0; // Keeps track of the next element to be inserted's index
        T *V; // Array to store the stack elements
        int N; // Stack max size
    
    public:
        // Class defined within .h file because apparently class templates cannot be defined in a separate file :)
        StackVet(int n)
        {
            V = new T[n];
            N = n;
        }

        bool empty() {return !top}

        void clear() {top = 0}

        T top() {return V[top - 1];}

        bool push(T e)
        {
            if (top == N) return false;
            V[top] = e;
            top++;
            return true;
        }

        bool pop()
        {
            if (top < 1) return false;

            top--;
            return true;
        }

        ~StackVet() {delete V}

};