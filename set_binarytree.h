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
    int depth;

public:
    Set()
    {
        root = nullptr;
        depth = 0;
    }
    ~Set()
    {
        if (depth == 0)
        {
            depth = 0;
        }
        else
        {
            cutDownTree(root);
        }
    }
    void insert(T data)
    {
        if (root != nullptr)
        {
            insert(root, data);
        } // if there is already a root
        else
        {
            root = new Node; // create new root
            root->data = data;
            root->left = nullptr;
            root->right = nullptr;
            ++depth;
        }
    }
    void insert(Node *leaf, T data)
    {
        if (data < leaf->data)
        {
            if (leaf->left != nullptr)
            {
                insert(leaf->left, data);
            }
            else
            {
                leaf->left = new Node;
                leaf->left->data = data;
                leaf->left->left = nullptr;
                leaf->left->right = nullptr;
                ++depth;
            }
        }
        else
        {
            if (leaf->right != nullptr)
            {
                insert(leaf->right, data);
            }
            else
            {
                leaf->right = new Node;
                leaf->right->data = data;
                leaf->right->left = nullptr;
                leaf->right->right = nullptr;
                ++depth;
            }
        }
    }
    void remove(T data)
    {
        remove(root, data);
        std::cout << "leaf trimmed...\n";
    }
    Node *remove(Node *leaf, T data)
    {
        if (leaf == NULL)
        {
            --depth;
            return leaf;
        }
        else if (data < leaf->data)
        {
            leaf->left = remove(leaf->left, data);
        }
        else if (data > leaf->data)
        {
            leaf->right = remove(leaf->right, data);
        }
        else
        {
            // No child
            if (leaf->right == NULL && leaf->left == NULL)
            {
                delete leaf;
                leaf = NULL;
                --depth;
            }
            // One child
            else if (leaf->right == NULL)
            {
                Node *temp = leaf;
                leaf = leaf->left;
                delete temp;
                --depth;
            }
            else if (leaf->left == NULL)
            {
                Node *temp = leaf;
                leaf = leaf->right;
                delete temp;
                --depth;
            }
            // two child
            else
            {
                while (leaf->right != NULL)
                {
                    leaf = leaf->right;
                }
                Node *temp = leaf;
                leaf->data = temp->data;
                leaf->left = remove(leaf->left, temp->data);
            }
        }

        return leaf;
    }
    int getSize()
    {
        return depth;
    }
    bool contains(T data)
    {
        return contains(root, data);
    }
    bool contains(Node *leaf, T data)
    {
        if (leaf == nullptr)
        {
            std::cout << "is null...\n";
            return false;
        }
        else if (data == leaf->data)
        {
            std::cout << "found it...\n";
            return true;
        }
        else if (data < leaf->data)
        {
            std::cout << "going down left side of tree...\n";
            return contains(leaf->left, data);
        }
        else
        {
            std::cout << "going down right side of tree...\n";
            return contains(leaf->right, data);
        }
    }
    void print()
    {
        return print(root);
    }
    void print(Node *leaf)
    {
        if (leaf)
        {
            std::cout << leaf->data << "\n";
            print(leaf->left);
            print(leaf->right);
        }
    }
    void cutDownTree(Node *leaf)
    {
        if (leaf)
        {
            // std::cout << "leaf trimmed...\n";
            cutDownTree(leaf->left);
            cutDownTree(leaf->right);
            delete leaf;
        }
        depth = 0;
    }
};