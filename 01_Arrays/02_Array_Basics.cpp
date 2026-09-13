#include <iostream>
using namespace std;

int main() {

```
// 1. Declaration

int arr[5];

// 2. Initialization

int marks[5] = {10, 20, 30, 40, 50};

int nums[] = {1, 2, 3};

// 3. Access

cout << marks[0] << endl;  // First element
cout << marks[4] << endl;  // Last element

// 4. Modification

marks[2] = 100;

cout << marks[2] << endl;

// 5. Find size of array

int n = sizeof(marks) / sizeof(marks[0]);

cout << "Size: " << n << endl;

// 6. Array name and pointer

int arr2[] = {1, 2, 3, 4, 5};

cout << *arr2 << endl;        // arr[0]
cout << *(arr2 + 1) << endl;  // arr[1]
cout << *(arr2 + 2) << endl;  // arr[2]

// arr[i] is equivalent to *(arr + i)

return 0;
```

}
