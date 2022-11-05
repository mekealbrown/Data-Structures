

template <typename T>
class Stack
{
    T *data{};
    int top{};
    public:
        Stack(int maxsize) {data = new T[maxsize]{};} //construct
        ~Stack() {delete [] data;} //delete dynamic array

        void push(T num) 
        {
            data[top] = num;
            ++top;
        }
        T pop() {return data[--top];}
        bool isEmpty() {return top == 0;}
};


