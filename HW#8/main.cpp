#include <iostream>

const float PI = 3.14159265358979323846;

float getArea(float radius) {
	return PI * radius * radius;
}

float getCircumference(float radius) {
	return 2 * PI * radius;
}

int factorialIterative(int count) {
	int result = 1;
	for (int i = 1; i <= count; ++i) {
		result *= i;
	}
	return result;
}

int factorialRecursive(int count) {
	if (count <= 1) {
		return 1;
	}
	return count * factorialRecursive(count - 1);
}

int main() {
	float radius;

	std::cout << "Enter radius: ";
	std::cin >> radius;

	std::cout << "Area: " << getArea(radius) << std::endl;
	std::cout << "Circumference: " << getCircumference(radius) << std::endl;

	double num;
	std::cout << "Enter number: ";
	std::cin >> num;
	std::cout << "Iterative factorial: " << num << " = " << factorialIterative(num) << std::endl;
	std::cout << "Recursive factorial: " << num << " = " << factorialRecursive(num) << std::endl;


	int positive = 0, negative = 0, zero = 0, n;

	std::cout << "Enter number of digits: ";
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int number;
		std::cout << "Enter number: ";
		std::cin >> number;

		if (number > 0) {
			positive++;
		}
		else if (number < 0) {
			negative++;
		}
		else {
			zero++;
		}
	}

	std::cout << "Positive: " << positive << std::endl;
	std::cout << "Negative: " << negative << std::endl;
	std::cout << "Zeroes: " << zero << std::endl;


	system("pause>0");
}