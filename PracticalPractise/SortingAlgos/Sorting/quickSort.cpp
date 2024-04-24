#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void quickSort(int *arr, int start, int end){
    if(start >= end) return;
    int pivot = end;
    int j = start;
    int i = start - 1;
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    quickSort(arr, start, i-1);
    quickSort(arr, i+1, end);
}
void printArray(int *arr, int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size = 6;
    int arr[] = {9, 10, 11, 6, 15, 2};
    quickSort(arr, 0, size-1);
    cout<<"Array after Quick Sorting : ";
    printArray(arr, size);
    return 0;
}