template <typename T>
class Set
{
private:
    class Node
    {
        public:
            T data;
            Node *left;
            Node *right;
            Node(T key)
            {
                this->data = key;
                this->left = this->right = nullptr;
            }
    };
    Node *root; int size;

public:
    Set();
    ~Set();
    void insert(T key);
    Node *insert(Node *ptr, T key);
    void remove(T key);
    Node *remove(Node *ptr, T key);
    bool contains(T key);
    Node *contains(Node *ptr, T key);
    void cutDown(Node *ptr);
    int getSize();
};

template <typename T>
Set<T>::Set()
{
    root = nullptr; size = 0;
}

template <typename T>
Set<T>::~Set()
{
   cutDown(root);
}


template <typename T>
void Set<T>::insert(T key)
{
    insert(root, key);
    ++size;
}

template <typename T>
typename Set<T>::Node *Set<T>::insert(Node *ptr, T key)
{
    if (!ptr)
    {
        return new Node(key);
    }
    else 
    {
        if (key > ptr->data) {ptr->right = insert(ptr->right, key);}
        else {ptr->left = insert(ptr->left, key);}
    }
    return ptr;
}

template <typename T>
void Set<T>::remove(T key)
{
    remove(root, key);
    --size;
}

template <typename T>
typename Set<T>::Node *Set<T>::remove(Node *ptr, T key)
{
    Node *hold = nullptr;
    if (ptr == nullptr) {return ptr;}
    else if (key > ptr->data) 
    {
        ptr->right = remove(ptr->right, key);
    }
    else if (key < ptr->data) 
    {
        ptr->left = remove(ptr->left, key);
    }
    else  
    {
        if (ptr->left == nullptr && ptr->right == nullptr) 
        {
            //ptr = nullptr;
            delete ptr;
        }
        else if (ptr->left && ptr->right)
        {
            Node *temp = ptr->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            ptr->data = temp->data;
            ptr->right = remove(ptr->right, key);
        } 
        else  
        {
            hold = (hold->left)? hold->left : hold->right;
            ptr->data = hold->data;
            delete hold;
        }
    }
    return ptr;
}

template<typename T>
void Set<T>::cutDown(Node *ptr)
{
    if (!ptr)
    {
        return;
    }
    cutDown(ptr->left);
    cutDown(ptr->right);
    delete ptr;
}

template <typename T>
bool Set<T>::contains(T key)
{
    return contains(root, key) == nullptr;
}

template <typename T>
typename Set<T>::Node *Set<T>::contains(Node *ptr, T key)
{
    if (ptr)
    {
        if (key > ptr->data)
        {
            ptr->right = contains(ptr->right, key);
        }
        else if (key < ptr->data)
        {
            ptr->left = contains(ptr->left, key);
        }
        else  
        {
            return ptr;
        }
    }
    return nullptr;
}

template<typename T>
int Set<T>::getSize()
{
    return size;
}