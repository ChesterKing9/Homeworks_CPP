#include <iostream>

const int ROWS = 4;
const int COLUMS = 4;

bool find(int arr_2d[ROWS][COLUMS], int toFind) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMS; ++j) {
			if (arr_2d[i][j] == toFind) {
				return true;
			}
		}
	}
	return false;
}

bool isSorted(const int* arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void fillArray(int arr_2d[ROWS][COLUMS]) {
	int value = 1;
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMS; ++j) {
			arr_2d[i][j] = value++;
		}
	}
}

void fillArraySpecial(int arr_2d[ROWS][COLUMS]) {
	int value = 1;
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMS; ++j) {
			arr_2d[i][j] = value;
			value += 2;
		}
	}
}

void printArray(int arr_2d[ROWS][COLUMS]) {
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLUMS; ++j) {
			std::cout << arr_2d[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

enum class SortingDirection { ascending, descending };

bool isSorted(const int* arr, int size, SortingDirection direction) {
	if (direction == SortingDirection::ascending) {
		for (int i = 0; i < size; ++i) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
	}
	else {
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] < arr[i + 1]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int arr2d[ROWS][COLUMS];
	fillArray(arr2d);
	std::cout << "2D Array:" << std::endl;
	printArray(arr2d);
	int toFind = 10;
	std::cout << "Searching Element" << toFind << ": ";
	std::cout << (find(arr2d, toFind) ? "Finded" : "NOT Finded") << std::endl;

	int arr[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Array sorted ascending: " <<
		(isSorted(arr, size) ? "YES" : "NOT") << std::endl;

	int specialArr[ROWS][COLUMS];
	fillArraySpecial(specialArr);
	std::cout << "Second 2D Array: " << std::endl;
	printArray(specialArr);

	int descArr[] = { 5, 4, 3, 2, 1 };
	int descSize = sizeof(descArr) / sizeof(descArr[0]);
	std::cout << "Descending Sorted: " <<
		(isSorted(descArr, descSize, SortingDirection::descending) ? "YES" : "NOT") << std::endl;

	return 0;
}