#include <cstddef>
#include <cstdlib>
template <typename T>
class Stack
{
    private:
        class Node
        {
            public:
                T data;
                Node *next;
                ~Node() { delete this->next;}
        };
        Node *head;
    public:
        Stack() { head = nullptr; }
        ~Stack() { delete this->head; }
        void push(const T &x)
        {
            Node *temp = new Node;
            temp->data = x;
            temp->next = head;
            head = temp;
        }
        T pop()
        {
            return head = head->next;
        }
        bool isEmpty() {return head == nullptr;}
};     
