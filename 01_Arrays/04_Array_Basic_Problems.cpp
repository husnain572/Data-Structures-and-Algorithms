#include <iostream>
#include <climits>
using namespace std;

// =========================================
// Find Smallest and Largest
// =========================================

void findSmallestLargest(int arr[], int size) {

```
int smallest = INT_MAX;
int largest = INT_MIN;

int minIndex = -1;
int maxIndex = -1;

for (int i = 0; i < size; i++) {

    if (arr[i] < smallest) {
        smallest = arr[i];
        minIndex = i;
    }

    if (arr[i] > largest) {
        largest = arr[i];
        maxIndex = i;
    }
}

cout << "Smallest: " << smallest
     << " at index " << minIndex << endl;

cout << "Largest: " << largest
     << " at index " << maxIndex << endl;
```

}

// =========================================
// Reverse Array
// =========================================

void reverseArray(int arr[], int size) {

```
int start = 0;
int end = size - 1;

while (start < end) {

    swap(arr[start], arr[end]);

    start++;
    end--;
}
```

}

// =========================================
// Sum and Product
// =========================================

void sumAndProduct(int arr[], int size) {

```
long long sum = 0;
long long product = 1;

for (int i = 0; i < size; i++) {

    sum += arr[i];
    product *= arr[i];
}

cout << "Sum: " << sum << endl;
cout << "Product: " << product << endl;
```

}

// =========================================
// Swap Minimum and Maximum
// =========================================

void swapMinMax(int arr[], int size) {

```
int minValue = INT_MAX;
int maxValue = INT_MIN;

int minIndex = -1;
int maxIndex = -1;

for (int i = 0; i < size; i++) {

    if (arr[i] < minValue) {
        minValue = arr[i];
        minIndex = i;
    }

    if (arr[i] > maxValue) {
        maxValue = arr[i];
        maxIndex = i;
    }
}

if (minIndex != -1 && maxIndex != -1) {
    swap(arr[minIndex], arr[maxIndex]);
}
```

}

int main() {

```
int arr[] = {9, 4, 3, 1, 0};

int size = sizeof(arr) / sizeof(arr[0]);

findSmallestLargest(arr, size);

reverseArray(arr, size);

cout << "Reversed: ";

for (int x : arr) {
    cout << x << " ";
}

cout << endl;

return 0;
```

}
