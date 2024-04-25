#include <iostream>
using namespace std;
int swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void heapify(int *arr, int size, int i){
    int largest = i;
    int l = 2*i+ 1;
    int r = 2*i + 2;
    if(l < size && arr[l] > arr[largest])
        largest = l;
    if(r < size && arr[r] > arr[largest])
        largest = r;
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapSort(int *arr, int size){
    for(int i=(size-1)/2;i>=0;i--){
        heapify(arr, size, i);
    }
    for(int i=size-1;i>=0;i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
void printArray(int *arr, int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){/*
    int size = 6;
    int arr[] = {9, 10, 11, 6, 15, 2};*/
    
    int size;
    cout<<"Enter array size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    heapSort(arr, size);
    printArray(arr, size);
    return 0;
}