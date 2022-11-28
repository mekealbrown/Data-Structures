#include <iostream>
#include "adt_list.h"

int main(int argc, char *argv[])
{
    (void)argc;
    List<int> s{};
    int data;
    while (std::cin >> data)
    {
        s.append(data);
    }
    int hold{}, test{};
    int div{std::stoi(argv[1])};
    for (List<int>::Iterator i{s.getHead()}; i; ++i)
    {
        
        do
        {
            if (i == 1)
            {
                ++i;
            }
            ++hold;
        } while (hold % div != 0);
        i.insert(test);
    }
    auto p = s.getHead();
    while (p)
    {
        std::cout << *p << " ";
        ++p;
    }
}