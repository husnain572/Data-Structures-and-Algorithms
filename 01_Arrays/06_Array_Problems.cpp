#include <iostream>
#include <unordered_set>
using namespace std;

// Print Unique Elements

void printUnique(int arr[], int size) {

```
unordered_set<int> seen;

for (int i = 0; i < size; i++) {

    if (seen.find(arr[i]) == seen.end()) {

        cout << arr[i] << " ";

        seen.insert(arr[i]);
    }
}

cout << endl;
```

}

// Intersection of Two Arrays

void printIntersection(
int arr1[],
int size1,
int arr2[],
int size2
) {

```
for (int i = 0; i < size1; i++) {

    for (int j = 0; j < size2; j++) {

        if (arr1[i] == arr2[j]) {

            cout << arr1[i] << " ";
            break;
        }
    }
}

cout << endl;
```

}

int main() {

```
// Unique Elements

int arr[] = {5, 12, 14, 72, 5, 14};

int size = sizeof(arr) / sizeof(arr[0]);

cout << "Unique elements: ";
printUnique(arr, size);

// Intersection

int arr1[] = {4, 3, 9, 6, 5, 7};
int arr2[] = {0, 5, 1, 9, 3};

int size1 = sizeof(arr1) / sizeof(arr1[0]);
int size2 = sizeof(arr2) / sizeof(arr2[0]);

cout << "Intersection: ";

printIntersection(arr1, size1, arr2, size2);

return 0;
```

}
