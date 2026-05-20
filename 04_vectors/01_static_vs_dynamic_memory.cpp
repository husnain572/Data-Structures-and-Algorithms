#include<iostream>
using namespace std;

int main() {

    // =========================================================
    // STATIC MEMORY ALLOCATION
    // =========================================================

    // Memory is allocated before program execution starts.
    // Size is fixed and cannot be changed during runtime.
    // Local variables are generally stored in stack memory.
    // Memory is automatically destroyed when function ends.

    int staticArr[5] = {1, 2, 3, 4, 5};

    cout << "Static Array: ";

    for(int i = 0; i < 5; i++) {
        cout << staticArr[i] << " ";
    }

    cout << endl << endl;


    // =========================================================
    // DYNAMIC MEMORY ALLOCATION
    // =========================================================

    // Memory is allocated during runtime using 'new'.
    // Dynamic memory is stored in heap memory.
    // Size can be decided at runtime.
    // Programmer must free memory manually using 'delete'.

    int size;

    cout << "Enter size of dynamic array: ";
    cin >> size;


    // Dynamic array creation
    int* dynamicArr = new int[size];



    // =========================================================
    // INSERTING VALUES
    // =========================================================

    cout << "Adding values in dynamic array:" << endl;

    for(int i = 0; i < size; i++) {
        dynamicArr[i] = i + 1;
    }



    // =========================================================
    // PRINTING VALUES
    // =========================================================

    cout << "Dynamic Array: ";

    for(int i = 0; i < size; i++) {
        cout << dynamicArr[i] << " ";
    }

    cout << endl;



    // =========================================================
    // MEMORY DEALLOCATION
    // =========================================================

    // delete[] is used for dynamically allocated arrays

    delete[] dynamicArr;

    // Good practice
    dynamicArr = nullptr;



    // =========================================================
    // PROGRAM END
    // =========================================================

    return 0;
}
