#include <iostream>
using namespace std;

// =========================================
// Linear Search
// =========================================

int linearSearch(int arr[], int size, int target) {

```
for (int i = 0; i < size; i++) {

    if (arr[i] == target) {
        return i;
    }
}

return -1;
```

}

int main() {

```
int arr[] = {4, 2, 6, 5, 8, 1, 9};

int size = sizeof(arr) / sizeof(arr[0]);

int target = 1;

int index = linearSearch(arr, size, target);

cout << "Index: " << index << endl;

return 0;
```

}
