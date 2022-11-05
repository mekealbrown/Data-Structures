#include <iostream>
#include "testing.h"

int main()
{
   LinkedList<int> list;
   list.print();
   list.insert(10);
   list.insert(15);
   list.insert(20);
   list.print();
   list.remove();
   list.remove();
   list.print();
}