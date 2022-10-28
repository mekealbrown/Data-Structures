#include <iostream>
#include <cassert>
#include "utility.h"

int main()
{
    int a[20] = {1, 2, 1, 4, 11, 6, 7};
    arrayReverse(a + 2, 3);
    for (int i = 0; i < 7; ++i)
    {
        std::cout << a[i] << ",";
    }
    //assert(a[2] == 5);
    //assert(a[4] == 3);
}