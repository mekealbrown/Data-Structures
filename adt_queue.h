template <typename T>
struct Queue {
    T       data[100];
    int     top = 0;
    int     bottom = 0;

    void    push(T v)   { data[top++] = v; }
    T       pop()       { return data[bottom++]; }
    bool    isEmpty()   { return top==bottom; }
    int     getSize()   { return top-bottom; }
};
