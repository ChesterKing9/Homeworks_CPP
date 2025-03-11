#pragma once
#include <cstdlib>

class DynamicIntArray
{
public:
    // Default constructor
    DynamicIntArray();

    // Constructor with size
    DynamicIntArray(std::size_t size);

    // Destructor
    ~DynamicIntArray();

    // Copy constructor
    DynamicIntArray(const DynamicIntArray& other);

    // Assignment operator
    DynamicIntArray& operator=(const DynamicIntArray& other);

    int& operator[](std::size_t index);

    // Clear internal memory, set size to 0
    void clear();

    // Comparison operators
    bool operator==(const DynamicIntArray& other);
    bool operator!=(const DynamicIntArray& other);

    std::size_t getSize() const;

    // Resize array, preserving old content if possible
    void setSize(std::size_t newSize);

    // Append an element to the array
    void push_back(int element);

private:
    int* m_data = nullptr;
    std::size_t m_size = 0;
};