#include <iostream>
using namespace std;
void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void bubble_sort(int array[], int size)
{
    bool is_swapped = false;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                is_swapped = true;
            }
        }
        if (is_swapped == false)
            return;
    }

    print_array(array, size);
}
int main()
{
    int arr[] = {4, 3, 2, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);
    return 0;
}