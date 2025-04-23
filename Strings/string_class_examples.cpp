#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    // Using C++ string class
    string str = "Husnain";
    string str1 = "Feroz";

    // Concatenation
    cout << str + " " + str1 << endl; // Outputs: Husnain Feroz
    cout << str.length() << endl;     // Outputs: length of str

    // Lexicographical comparison
    cout << (str < str1) << endl;     // 1 if str < str1, else 0

    // Using getline for input
    string str4;
    getline(cin, str4, '$');
    cout << str4 << endl;

    // Loop through characters — traditional loop
    for (int i = 0; i < str4.length(); i++) {
        cout << str4[i] << " ";
    }
    cout << endl;

    // Range-based for loop
    for (char ch : str4) {
        cout << ch;
    }
    cout << endl;

    return 0;
}
