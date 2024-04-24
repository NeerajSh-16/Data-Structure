//It will work only for the array of size 8
#include <iostream>
using namespace std;
void merge(int *arr, int *temp, int start , int mid, int end){
    int i = start, j = mid + 1, k = start;
    while(i <= mid && j <= end){
       if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
       }else{
        temp[k++] = arr[j++];
       }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    while(start <= end){
        arr[start] = temp[start];
        start++;
    }
}
void mergeSort(int *arr, int *temp, int start, int end){
    if(start >= end) return;
    int mid = (start + end) >> 1;
    mergeSort(arr, temp, start, mid);
    mergeSort(arr, temp, mid+1, end);
    merge(arr, temp, start, mid, end);
}
void sortArray(int *arr, int size){
    int temp[6] = {0};
    mergeSort(arr, temp, 0, size-1);
}
void printArray(int *arr, int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
   // int size = 6;
    //int arr[] = {10, 9, 11, 6, 15, 2};
    int size;
    cout<<"Enter array size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    sortArray(arr, size);
    printArray(arr, size);
    return 0;
}