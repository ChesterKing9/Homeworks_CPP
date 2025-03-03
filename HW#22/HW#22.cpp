#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

bool compareByLength(const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

class LengthComparator {
public:
    bool operator()(const std::string& a, const std::string& b) const {
        return a.size() < b.size();
    }
};

unsigned int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(), [number](int x) {
        return x % number == 0;
        });
}

int main() {
    std::srand(std::time(nullptr));

    std::vector<std::string> stringContainer = { "apple", "banana", "kiwi", "strawberry", "grape", "mango" };

    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
    std::cout << "Sorted using function: ";
    for (const auto& str : stringContainer) std::cout << str << " ";
    std::cout << "\n";

    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());
    std::cout << "Sorted using functor: ";
    for (const auto& str : stringContainer) std::cout << str << " ";
    std::cout << "\n";

    std::sort(stringContainer.begin(), stringContainer.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
        });
    std::cout << "Sorted using lambda: ";
    for (const auto& str : stringContainer) std::cout << str << " ";
    std::cout << "\n";

    std::vector<int> numbers = { 10, 25, 30, 40, 55, 60, 75, 80, 100 };
    int divisor = 5;

    unsigned int count = countDivisibleBy(numbers, divisor);
    std::cout << "Count of numbers divisible by " << divisor << ": " << count << "\n";

    return 0;
}
