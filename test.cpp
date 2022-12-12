#include "set_binarytree.h"
#include "cstdlib"
#include "cassert"
#include <iostream>
#include "testing.h"


using namespace std;

int main()
{
    Set<int> S;
    assert(S.getSize()==0);

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