#include <iostream>
template <typename T>
class Queue
{
    private:
        class Node
        {
            public:
                T data;
                Node *next;
        };
        Node *head;
        Node *tail;
    public:
        Queue() { head = nullptr; tail = nullptr;}  
        ~Queue() 
        {                         
            Node *current = head;
            while (current != nullptr) 
            {
                Node *next = current->next; 
                delete current;
                current = next;
            }
        }
        void push(const T &x)
        {
            Node *temp = new Node;
            temp->data = x;
            if (tail == nullptr)
            {
                head = temp;
                tail = temp;
                return;
            }
            tail->next = temp;
            tail = temp;
        }
        T pop()
        {
            Node *temp = head;
            T data = temp->data;
            head = temp->next;
            delete temp;
            return data;
        }
        
};     
