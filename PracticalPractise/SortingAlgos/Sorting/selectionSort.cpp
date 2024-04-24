#include <iostream>
using namespace std;
void selectionSort(int *arr, int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void printArray(int *arr, int size){
    for(int i=0;i<size;i++){
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
    selectionSort(arr, size);
    cout<<"Array after Selection Sorting : ";
    printArray(arr, size);
    return 0;
}