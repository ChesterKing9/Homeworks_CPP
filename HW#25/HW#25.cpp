#include <iostream>
#include <SFML/Graphics.hpp>
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

    void draw(sf::RenderWindow& window, sf::Vector2f origin = sf::Vector2f(0, 0)) const {
        sf::Vertex line[2];
        line[0].position = origin;
        line[0].color = sf::Color::Black;
        line[1].position = origin + sf::Vector2f(x, y);
        line[1].color = sf::Color::Black;

        window.draw(line, 2, sf::PrimitiveType::Lines);
    }
};

int Vector2d::instanceCount = 0;

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1366, 768 }), "Vector Visualization");

    Vector2d v1(100, 150);
    Vector2d v2(200, 100);
    Vector2d v3 = v1 + v2;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        v1.draw(window);
        v2.draw(window);
        v3.draw(window);

        window.display();
    }

    return 0;
}
