#include <iostream>

template <typename T>
class Set
{
private:
    class Node
    {
    public:
        T data;
        Node *left, *right;
    };
    Node *root;
    int size;

public:
    Set();
    ~Set();
    void insert(T data);
    void remove(T data);
    Node * remove(Node *leaf, T data);
    bool contains(T data);
    int getSize();
};


template<typename T> Set<T>::Set() { root = nullptr; size = 0;}

template<typename T> Set<T>::~Set() {}

template<typename T> void Set<T>::insert(T data) 
{
    Node *leaf = new Node;
    leaf->data = data;
    if (root == nullptr) { root = leaf;}
    else  
    {
        Node *temp = root;
        while (true)
        {
            if (data > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = leaf;
                    break;
                }
                temp = temp->right;
            }
            else 
            {
                if (temp->left == nullptr)
                {
                    temp->left = leaf;
                    break;
                }
                temp = temp->left;
            }
        }
    }
    ++size;
}

template<typename T> void Set<T>::remove(T data) //trying recursion here
{
    remove(root, data);
}

template<typename T>
typename Set<T>::Node* Set<T>::remove(Node *leaf, T data)
{
    if (root == nullptr) { return root; }
    if (data > leaf->data)
    {
        leaf = remove(leaf->right, data);
    }
    else if (data < leaf->data)
    {
        leaf = remove(leaf->left, data);
    }
    else  
    {
        
    }
    return root;
}

template<typename T> bool Set<T>::contains(T data)
{
    Node *temp = root;
    while (temp != nullptr)
    {
        if (temp->data == data)
        {
            return true;
        }
        if (temp->data < data)
        {
            temp = temp->left;
        }
        else  
        {
            temp = temp->right;
        }
    }
    return false;
}

template<typename T> int Set<T>::getSize()
{
    return size;
}