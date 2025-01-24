#include <iostream>
#include <cstring>

//Exercise 3
bool isPalindrom(const char str[]) {
	int left = 0;
	int right = strlen(str) - 1;

	while (left < right) {
		if (tolower(str[left]) != tolower(str[right])) {
			return false;
		}
		left++;
		right--;
	}
	return true;
}

//Exercise 2
void toUppercase(char str[]) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - ('a' - 'A');
		}
	}
}

//Exercise 1
void translateArray(int numbers[], int size) {
	for (int i = 0; i < size; ++i) {
		if (numbers[i] > 0) {
			numbers[i] *= 2;
		}
		else if (numbers[i] < 0) {
			numbers[i] = 0;
		}
	}
}

//Exercise 1
void printArray(const int numbers[], int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
}

int main() {

	char str[100];

	std::cout << "Enter raw: ";
	std::cin.getline(str, 100);

	if (isPalindrom(str)) {
		std::cout << "IT is Palindrom." << std::endl;
	}
	else {
		std::cout << "It is NOT Palindrom." << std::endl;
	}

	const int SIZE = 10;
	int numbers[SIZE];

	char str[SIZE];

	std::cout << "Enter raw: " << std::endl;
	std::cin.getline(str, SIZE);


	toUppercase(str);

	std::cout << "Processed raw: " << str << std::endl;

	std::cout << "Enter 10 elements: " << std::endl;
	for (int i = 0; i < SIZE; ++i) {
		std::cin >> numbers[i];
	}

	translateArray(numbers, SIZE);

	std::cout << "Processed Array: ";
	printArray(numbers, SIZE);

	system("pause>0");
}