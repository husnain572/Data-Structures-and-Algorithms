
#include <iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int smallest_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest_idx]){
                smallest_idx=j;
            }
        }
       swap(arr[i],arr[smallest_idx]);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n=7;
    int arr[]={14,5,72,12,135,110,127};
    selectionSort(arr,n);
    printArray(arr,n);
    return 0;
}
