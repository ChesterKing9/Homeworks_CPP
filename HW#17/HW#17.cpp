#include <iostream>
#include <cmath>

class Vector2d {
private:
    float x, y;
    static int instanceCount; 

public:
    Vector2d(float x = 0.0, float y = 0.0) : x(x), y(y) { instanceCount++; }
    Vector2d(const Vector2d& other) : x(other.x), y(other.y) { instanceCount++; }
    ~Vector2d() { instanceCount--; }

    Vector2d& operator=(const Vector2d& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    float& operator[](std::size_t idx) {
        if (idx == 0) return x;
        else if (idx == 1) return y;
        throw std::out_of_range("Index out of range");
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec) {
        os << "{" << vec.x << "; " << vec.y << "}";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector2d& vec) {
        is >> vec.x >> vec.y;
        return is;
    }

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
        return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
    }

    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
        return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
    }

    void operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
    }

    float operator()() const {
        return std::sqrt(x * x + y * y);
    }

    static int getInstanceCount() {
        return instanceCount;
    }
};

int Vector2d::instanceCount = 0;

int main() {
    Vector2d v1(1.2, 5.6);
    Vector2d v2(3.4, -2.1);
    Vector2d v3 = v1 + v2;
    std::cout << "v1: " << v1 << "\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "v3 = v1 + v2: " << v3 << "\n";

    v1 *= 2.0;
    std::cout << "v1 after scaling: " << v1 << "\n";
    std::cout << "v1 length: " << v1() << "\n";

    std::cout << "Active instances: " << Vector2d::getInstanceCount() << "\n";
    return 0;
}
