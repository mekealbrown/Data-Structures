#include <iostream>
#include "utility.h"

void arrayReverse(int *p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        *(p + i) = *(p + (n - 1)) - i;
    }
}