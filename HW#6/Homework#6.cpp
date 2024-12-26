#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    double a1, d, n;

    cout << "Enter first element: ";
    cin >> a1;
    cout << "Enter step of arithmetic progression: ";
    cin >> d;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Arithmetic progression elements: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a1 + i * d << " ";
    }
    cout << endl;


    char symbol;
    int sum = 0;

    cout << "Enter symbols ('.' to close): " << endl;

    while (true) {
        cin >> symbol;

        if (symbol == '.') {
            break;
        }

        if (isalpha(symbol)) {
            cout << "Uppercace symbol: " << char(toupper(symbol)) << endl;
        }
        else if (isdigit(symbol)) {
            sum += symbol - '0';
            cout << "Sum of numbers: " << sum << endl;
        }
        else {
            cout << "Invalid symbol: " << symbol << endl;
        }
    }

    int size;
    cout << "Enter number: " << endl;
    cin >> size;

    cout << "a\n";
    for (int i = size; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "b\n";
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "c\n";
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "d\n";
    int stars = 4;
    for (int i = 1; i <= size; ++i) {
        for (int k = 1; k < i; ++k) {
            cout << " ";
        }

        for (int j = 1; j <= stars; ++j) {
            cout << "*";
    }
        cout << endl;
    }


    cout << "e\n";
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << (j%2);
        }
        cout << endl;
    }

    //Additional 2

    int number;
    cout << "Enter number: ";
    cin >> number;

    int factorial = 1;
    for (int i = 1; i <= number; i++) {
        factorial = factorial * i;
    }

    cout << number << "!=" << factorial;

    
   
    system("pause > 0");
}

