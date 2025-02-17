#include <iostream>
#include "DynamicIntArray.h"

int main() {
    // Testing of ALL methods, constructors, and destructors
    DynamicIntArray myArray;
    std::cout << "Initial size: " << myArray.getSize() << std::endl;

    myArray.setSize(5);
    std::cout << "Size after setSize(5): " << myArray.getSize() << std::endl;

    for (std::size_t i = 0; i < myArray.getSize(); ++i) {
        myArray[i] = static_cast<int>(i * 10);
    }

    for (std::size_t i = 0; i < myArray.getSize(); ++i) {
        std::cout << "Element at " << i << ": " << myArray[i] << std::endl;
    }

    myArray.push_back(50);
    std::cout << "Size after push_back(50): " << myArray.getSize() << std::endl;
    std::cout << "Last element: " << myArray[myArray.getSize() - 1] << std::endl;

    myArray.clear();
    std::cout << "Size after clear(): " << myArray.getSize() << std::endl;

    return 0;
}
