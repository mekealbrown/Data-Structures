#include <iostream>

int find(int *arr, int n, int len)
{
    for (int i{0}; i < len - 1; ++i)
    {
        if (arr[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int *arr = new int[argc - 1];
    for (int i{0}; i < argc - 1; ++i) 
    {
        arr[i] = std::stoi(argv[i + 1]);
    }
    int *results = new int[argc - 1];
    for (int j{0}; j < argc - 2; ++j)
    {
        results[j] = std::abs(((arr[j] - arr[j + 1])));
    }
    int test{1};
    for (int k{0}; k < argc - 2; ++k)
    {
        if (!find(results, k + 1, argc - 1))
        {
            std::cout << "Bad sequence: missing " << k + 1 << std::endl;
            test = 0;
            break;
        }
    }
    if (test == 1)
    {
        std::cout << "Good sequence." << std::endl;
    }
}