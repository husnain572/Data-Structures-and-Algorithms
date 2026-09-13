#include <iostream>
using namespace std;

// Print Array

void printArray(int arr[], int size) {

```
for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
}

cout << endl;
```

}

// Input Array

void inputArray(int arr[], int size) {

```
for (int i = 0; i < size; i++) {
    cin >> arr[i];
}
```

}

// Modify Array

void changeArray(int arr[], int size) {

```
for (int i = 0; i < size; i++) {
    arr[i] *= 2;
}
```

}

int main() {

```
int arr[] = {1, 2, 3, 4, 5};

int n = sizeof(arr) / sizeof(arr[0]);

// Classic for loop

for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}

cout << endl;

// Range-based for loop

for (int x : arr) {
    cout << x << " ";
}

cout << endl;

// Function call

printArray(arr, n);

// Modify original array

changeArray(arr, n);

printArray(arr, n);

return 0;
```

}
