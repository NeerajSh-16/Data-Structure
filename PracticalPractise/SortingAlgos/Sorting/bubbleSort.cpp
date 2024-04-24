#include <iostream>
using namespace std;
void bubbleSort(int *arr, int size){
    int sizeCpy = size;
    while(sizeCpy--){
        int bubble = 0;
        for(int i=1;i<=sizeCpy;i++){
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
void printArray(int arr[], int size){
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
    bubbleSort(arr, size);
    cout<<"Array after Bubble Sorting : ";
    printArray(arr, size);
    return 0;
}