

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
    Set() {root = nullptr; size = 0;} 
    ~Set()
    {
        while (getSize() != 0)
        {
            remove(root->data);
        }
    }
    void insert(T key)
    {
        insert(root, key);
    }
    Node *insert(Node *&ptr, T key)
    {
        if (contains(key) == false)
        {
            if (ptr == nullptr)
            {
                ptr = new Node(key);
                //std::cout << "inserted..." << ptr->data << "\n";
                ++size;
                //return ptr;
            }
            else 
            {
                if (key > ptr->data)
                {
                    ptr->right = insert(ptr->right, key);
                }
                else 
                {
                    ptr->left = insert(ptr->left, key);
                }
            }
        }
        return ptr;
    }
    void remove(T key)
    {
        remove(root, key);
        --size;
    }
    Node *remove(Node *&node, T key)
    {
        if (node->data > key)
        {
            node->left = remove(node->left, key);
        }
        else if (node->data < key)
        {
            node->right = remove(node->right, key);
        }
        else  
        {
            if (!node->left && !node->right)
            {
                delete node;
                node = nullptr;
            }
            else if (node->left && node->right)
            {
                Node *temp = node;
                temp = temp->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
            else  
            {
                Node *p = (node->left)? node->left:node->right;
                delete node;
                node = p;
            }
        }
        return node;
    }
    bool contains(T key)
    {
        Node *temp = root;
        while (temp)
        {
            ////std::cout << temp->data << "\n";
            if (temp->data == key)
            {
                return true;
            }
            if (key > temp->data)
            {
                temp = temp->right;
            }
            else  
            {
                temp = temp->left;
            }
            
        }
        return false;
    }
    int getSize()
    {
        return size;
    }
    void print()
    {
        print(root);
        //std::cout << std::endl;
    }
    void print(Node *node)
    {
        if (node != nullptr)
        {
            print(node->left);
            //std::cout << node->data << " - ";
            print(node->right);
        }
    }
};