#include <cstddef>
#include <iostream>
template <typename T>
struct Node 
{
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class LinkedList
{
    Node<T> *head;

    public:
        LinkedList() 
        {
            head = NULL;
        }
        ~LinkedList() {delete head;}

        void insert(T data)
        {
            Node<T> *temp = new Node<T>(data);
            temp->next = head;
            head = temp;
        }

        T remove()
        {
            Node<T> *temp = head;
            Node<T> *previous;
            while (temp != NULL)
            {
                previous = temp;
                temp = temp->next;
            }
            previous->next = NULL;
            return temp->data;
            delete temp;
        }

        void print()
        {
            Node<T> *temp = head;
            std::string under{};
            std::cout << "|";
            while (temp != NULL)
            {
                std::cout << "--";
                std::cout << temp->data << "|";
                temp = temp->next;
                under += "__";
            }
            std::cout << under << "\n";
        }
};