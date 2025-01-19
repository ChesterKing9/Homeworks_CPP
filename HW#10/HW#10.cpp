#include<iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap(int*a, int*b) {
	if (a != nullptr && b != nullptr) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

bool find(const int* arr, int size, int elem) {
	const int* end = arr + size;
	for (const int* ptr = arr; ptr < end; ++ptr) {
		if (*ptr == elem) {
			return true;
		}
	}
	return false;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
	if (arrSize <= 0) {
		return false;
	}

	sum = 0;
	const double* end = arr + arrSize;
	for (const double* ptr = arr; ptr < end; ++ptr) {
		sum += *ptr;
	}
	return true;
}

int main() {
	int x = 5, y = 10;
	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap (by reference): x = " << x << ", y = " << y << std::endl;
	swap(&x, &y);
	std::cout << "After swap (by pointer): x = " << x << ", y = " << y << std::endl;

	int arr[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int elem = 3;
	if (find(arr, size, elem)) {
		std::cout << elem << " is found in the array." << std::endl;
	}
	else {
		std::cout << elem << " is not found in the array." << std::endl;
	}

	double arrD[] = { 1.1, 2.2, 3.3, 4.4 };
	int arrDSize = sizeof(arrD) / sizeof(arrD[0]);
	double sum;
	if (calculateSum(arrD, arrDSize, sum)) {
		std::cout << "Sum of array elements: " << sum << std::endl;
	}
	else {
		std::cout << "Array size is 0 or negative." << std::endl;
	}
	return 0;
}