template <typename T>
class Set
{
private:
    class Node
    {
        T data;
        Node *left;
        Node *right;
    } Node *root;

public:
    Set();
    ~Set();
    void insert(T key);
    Node *insert(Node *ptr, T key);
    void remove(T key);
    Node *remove(Node *ptr, T key);
    bool contains(T key);
    Node *contains(Node *ptr, T key);
}

template <typename T>
Set<T>::Set()
{
    root = nullptr;
}

template <typename T>
Set<T>::~Set()
{
}

template <typename T>
void Set<T>::insert(T key)
{
    insert(root, key);
}

template <typename T>
Set<T>::Node *Set<T>::insert(Node *ptr, T key)
{
}

template <typename T>
void Set<T>::remove(T data)
{
    remove(root, key);
}

template <typename T>
Set<T>::Node *Set<T>::remove(Node *ptr, T key)
{
}

template <typename T>
bool Set<T>::contains(T key)
{
    return contains(root, key) == nullptr;
}

template <typename T>
Set<T>::Node *Set<T>::contains(Node *ptr, T key)
{
}