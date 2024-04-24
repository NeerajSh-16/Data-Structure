#include <iostream>
using namespace std;
void insertionSort(int *arr, int size){
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j = i-1;
        while(j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;//Ye isliye h taki jub bhi kabhi swapping ho to key ko uski sahi jagah par pahucha dia jae
    }
}
void printArray(int *arr, int size){
    for(int i=0;i<size;i++){
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
    insertionSort(arr, size);
    cout<<"Your array after Insertion Sorting : ";
    printArray(arr, size);
    return 0;
}