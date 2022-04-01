#include <iostream>
#include "array.hpp"

int main()
{
    int arr[] = {1,2,3,4,5};
    std::cout<< array_sum(arr)<<std::endl;
    std::cout<< sum(arr);
    return 0;
}