#include <cstddef>
#include <type_traits>
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
    public:
        Set() { root = nullptr; }
        ~Set()
        {
            cutDownTree(root);
        }
        void insert(T data)
        {
            if (root != nullptr) { insert(root, data);} //if there is already a root
            else  
            {
                root = new Node;          //create new root
                root->data = data;
                root->left = nullptr;
                root->right = nullptr;
            }
        }
        void insert(Node *leaf, T data)
        {
            if (data < leaf->data)
            {
                if (leaf->left != nullptr) { insert(leaf->left, data);}
                else  
                {
                    leaf->left = new Node;
                    leaf->left->data = data;
                    leaf->left->left = nullptr;
                    leaf->left->right = nullptr;
                }
            } 
            else  
            {
                if (leaf->right != nullptr) { insert(leaf->right, data);}
                else  
                {
                    leaf->right = new Node;
                    leaf->right->data = data;
                    leaf->right->left = nullptr;
                    leaf->right->right = nullptr;
                }
            }
        }
        int getSize()
        {
            if (root == nullptr) { return 0;}
            else  
            {
                getSize(root);
            }
            return 0;
        }
        int getSize(Node *leaf)
        {
            if (leaf == nullptr) {return 0;}
            else  
            {
                return (getSize(leaf->left) + 1 + getSize(leaf->right));
            }
        }
        bool contains(T data)
        {
            return contains(root, data);
        }
        bool contains(Node *leaf, T data)
        {
            if (leaf == nullptr) { return false;}
            else if (data == leaf->data) { return true;}
            else if (data < leaf->data) { return contains(leaf->left, data);}
            else { return contains(leaf->right, data); }
        }
        void cutDownTree(Node *leaf)
        {
            if (leaf)
            {
                cutDownTree(leaf->left);
                cutDownTree(leaf->right);
                delete leaf;
            }
        }
};