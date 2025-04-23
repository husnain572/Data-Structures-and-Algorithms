#include <iostream>
#include <cstring> // Required for strlen
using namespace std;

int main() {
    // Not a valid string (no null-terminator '\0')
    char str[] = {'a', 'b', 'c'};
    cout << str << endl;        // Undefined behavior
    cout << strlen(str) << endl; // Undefined behavior

    // Proper null-terminated string
    char str1[] = {'a', 'b', 'c', '\0'};
    cout << str1 << endl;       // Outputs: abc
    cout << strlen(str1) << endl; // Outputs: 3

    // Recommended way to declare string
    char str2[] = "Husnain";
    cout << str2[4] << endl;    // Outputs: 'n'

    // Input limitations with cin
    char str3[100];
    cin >> str3;                // Only reads until space
    cout << str3 << endl;

    // Better input with cin.getline
    cin.getline(str3, 50, '.'); // Reads until '.'
    cout << str3 << endl;

    return 0;
}
