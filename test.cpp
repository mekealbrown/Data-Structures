#include "set_binarytree.h"
#include "cstdlib"
#include "cassert"
#include <iostream>
#include "testing.h"

int main()
{
   Set<int> s;
   assert(s.getSize()==0);
   
   int a[] = {1,4,3,6,5,2,7,9};
   for (int x : a)
       s.insert(x);
   assert(s.contains(5));
   assert(!s.contains(11));
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