#include "set_binarytree.h"
#include "cstdlib"
#include "cassert"
#include <iostream>
#include "testing.h"
#include <iostream>


using namespace std;

int main()
{
    Set<int> S;
    int values[] = {1,3,5,7,9,11,13,12,10,8,6,4,2,0};
    for (int i=0; i<14; i++)
        S.insert(values[i]);
    S.remove(1);
    S.insert(1);
    S.remove(3);
    S.insert(3);
    assert(S.getSize()==14);
}


