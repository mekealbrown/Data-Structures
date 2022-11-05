// Iterative C++ program to reverse a linked list
#include <bits/stdc++.h>
#include <cstddef>

struct Node 
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() {head = NULL;}

    void reverse()
    {
        Node *current{head};
        Node *previous{NULL}, *next{NULL};
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << " - ";
            temp = temp->next;
        }
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList llist;
    int x{5};
    for (int i{0}; i < 5; ++i)
    {
        llist.push(x);
        x *= 2;
    }
    llist.print();
    std::cout << "\n";
    llist.reverse();
    llist.print();
}