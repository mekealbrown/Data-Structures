#include <iostream>

int main(int argc, char *argv[])
{
    int *arr = new int[argc - 1];
    int diff{};
    for (int i{0}; i < argc - 2; ++i)
    {
        diff = std::abs((std::stoi(argv[i + 1]) - std::stoi(argv[i + 2])));
        arr[diff - 1] = diff;
    }
    bool test{true};
    for (int j{0}; j < argc - 2; ++j)
    {
        if (arr[j] != j + 1)
        {
            std::cout << "Bad sequence: missing " << j + 1 << std::endl;
            test = false;
            break;
        }
    }
    if (test == true)
    {
        std::cout << "Good sequence." << std::endl;
    }
}

// all individual loops are argc time
// place differences into array at index the num would be at eg. arr[2] = 3;