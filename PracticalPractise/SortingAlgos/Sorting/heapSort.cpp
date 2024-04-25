#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void heapify(int *arr, int size, int i){
    int largest = i;//parent index;
    int l = 2*i+1;
    int r = 2*i+2;
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
    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr, size, i);// to bring max element to top
    }
    for(int i = size-1; i >= 0; i--){
        swap(arr[i], arr[0]);//swap smallest and largest
        heapify(arr, i, 0);//decrease array size and again bring max element to the top
    }
}
void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    //int size = 6;
    //int arr[] = {9, 10, 11, 6, 15, 2};
    int size;
    cout<<"Enter array size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    heapSort(arr, size);
    cout<<"Array after sorting : ";
    printArray(arr, size);
    return 0;
}