#include <iostream>
#include "adt_list.h"

int main(int argc, char *argv[])
{
    List<int> s{};
    int data;
    while (std::cin >> data)
    {
        s.append(data);
    }
    int hold, val;
    int div{std::stoi(argv[1])};
    for (List<int>::Iterator i{s.getHead()}; i; ++i)
    {
        if (!*i % div)
        {
            val = *i;
            hold = i.index;
            i.remove();
        }
        if (val % div)
        {
            i.insert(hold);
        }
        ++val;
    }
    auto p = s.getHead();
    while (p)
    {
        std::cout << *p << " ";
        ++p;
    }
}