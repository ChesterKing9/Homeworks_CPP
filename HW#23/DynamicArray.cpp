#include <iostream>
#include "DynamicArray.h"

int main() {
    DynamicArray<int> arr;

    arr.reserve(5);  
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    std::cout << "Array size: " << arr.getSize() << std::endl;
    std::cout << "Array capacity: " << arr.getCapacity() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;

    arr.pop_back();
    std::cout << "Last element after pop_back: " << arr.back() << std::endl;

    arr.shrinkToFit();
    std::cout << "Capacity after shrinkToFit: " << arr.getCapacity() << std::endl;

    return 0;
}
