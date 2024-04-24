#include <iostream>
using namespace std;
/*void insertionSort(int *arr, int size){
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j = i -1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}*/
/*
void merge(int *arr, int *temp, int start, int mid, int end){
    int i = start, j = mid + 1, k = start;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= end) temp[k++] = arr[j++];
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
    int temp[size] = {0};
    mergeSort(arr, temp, 0, size-1);
}*/
void bubbleSort(int *arr, int size){
    int sizeCpy = size;
    while(sizeCpy--){
        int bubble = 0;
        for(int i=1;i<size;i++){
            if(arr[bubble] > arr[i]){
                int temp = arr[bubble];
                arr[bubble] = arr[i];
                arr[i] = temp;
                bubble++;
            }else{
                bubble++;
            }
        }
    }
}
void printArray(int *arr, int size){
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter array size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //insertionSort(arr, size);
    //sortArray(arr, size);
    bubbleSort(arr, size);
    cout<<"Array after Sorting : ";
    printArray(arr, size);
    return 0;
}