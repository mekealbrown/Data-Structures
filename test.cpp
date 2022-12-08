#include "set_binarytree.h"
#include "cstdlib"
#include "cassert"
#include <iostream>
#include "testing.h"

int main()
{
    Set<int> S;
    int values[] = {1, 3, 5, 7, 9, 11, 13, 12, 10, 8, 6, 4, 2, 0};
    for (int i = 0; i < 14; i++)
        S.insert(values[i]);
    S.remove(1);
    // assert(!S.contains(1));
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