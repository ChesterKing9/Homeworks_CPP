#include <iostream>
#include <algorithm>

const int ROWS = 3;
const int COLUMNS = 4;

enum class SortingDirection {
    ByRows,
    ByColumns
};

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sort(int arr[ROWS][COLUMNS], SortingDirection direction) {
    if (direction == SortingDirection::ByRows) {
        for (int i = 0; i < ROWS; ++i) {
            bubbleSort(arr[i], COLUMNS);
        }
    }
    else if (direction == SortingDirection::ByColumns) {
        for (int col = 0; col < COLUMNS; ++col) {
            int temp[ROWS];
            for (int row = 0; row < ROWS; ++row) {
                temp[row] = arr[row][col];
            }


            bubbleSort(temp, ROWS);


            for (int row = 0; row < ROWS; ++row) {
                arr[row][col] = temp[row];
            }
        }
    }
}


void printArray(int arr[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int array[ROWS][COLUMNS] = {
        {4, 2, 3, 1},
        {8, 7, 6, 5},
        {12, 11, 10, 9}
    };

    std::cout << "Original Array:\n";
    printArray(array);


    sort(array, SortingDirection::ByRows);
    std::cout << "\nSorted by Rows:\n";
    printArray(array);

    sort(array, SortingDirection::ByColumns);
    std::cout << "\nSorted by Columns:\n";
    printArray(array);

    return 0;
}
