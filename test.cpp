#include "queue_ll.h"
#include "cstdlib"
#include "cassert"
#include <iostream>
using namespace std;

int main()
{
    Queue<int> s;
    s.push(804);
    int x = s.pop();
    assert(s.isEmpty());
    std::cout << x << "\n";
}

// Node *ptr = new Node;
//         ptr->data = x;
//         if (tail == nullptr)
//         {
//             head = tail = ptr;
//             return;
//         }
//         tail->next = ptr;
//         tail = ptr;