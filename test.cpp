#include "set_binarytree.h"
#include "cstdlib"
#include "cassert"
#include <iostream>
#include "testing.h"

int main()
{
    Set<char> S;
    S.insert('A');
    S.insert('B');
    S.insert('C');
    S.remove('C');
    S.remove('B');
    assert(S.contains('A'));
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