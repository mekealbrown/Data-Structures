template <typename T>
class Queue
{
    T *data;
    int head;
    int tail;
    int max;

public:
    Queue(int maxsize)
    {
        data = new T[maxsize]{};
        head = 0;
        tail = 0;
        max = maxsize;
    }
    ~Queue() { delete[] data; }
    void push(T x)
    {
        tail = (tail + 1) % max;
        data[tail] = x;
    }
    T pop()
    {
        head = (head + 1) % max;
        return data[head];
    }
    bool isEmpty() { return tail == head; }
    int getSize()
    {
        if (tail > head)
        {
            return tail - head;
        }
        else if (tail < head)
        {
            return tail - head + max;
        }
        else
            return 0;
    }
    int getHead() { return head; }
    int getTail() { return tail; }
};