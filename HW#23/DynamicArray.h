#pragma once
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <algorithm>

// Template class for dynamic array
template <typename T>
class DynamicArray {
public:
    DynamicArray() : data(nullptr), size(0), capacity(0) {}
    DynamicArray(std::size_t size) : size(size), capacity(size), data(new T[size]) {}
    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity), data(new T[other.capacity]) {
        std::copy(other.data, other.data + size, data);
    }
    ~DynamicArray() { delete[] data; }

    bool operator==(const DynamicArray& other) const {
        if (size != other.size) return false;
        for (std::size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    T& operator[](std::size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    void setSize(std::size_t newSize) {
        if (newSize > capacity) {
            reallocate(newSize);
        }
        size = newSize;
    }

    std::size_t getSize() const { return size; }

    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    void push_back(const T& element) {
        if (size == capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = element;
    }

    void pop_back() {
        if (size > 0) --size;
    }

    T back() const {
        if (size == 0) throw std::out_of_range("Array is empty");
        return data[size - 1];
    }

    void reserve(std::size_t reservedSpace) {
        if (reservedSpace > capacity) {
            reallocate(reservedSpace);
        }
    }

    std::size_t getCapacity() const { return capacity; }

    void shrinkToFit() {
        if (size < capacity) {
            reallocate(size);
        }
    }

private:
    T* data;
    std::size_t size;
    std::size_t capacity;

    void reallocate(std::size_t newCapacity) {
        T* newData = new T[newCapacity];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};
