#include <iostream>
using namespace std;
int findSmallest(int *arr,int size, int index){
    int result = 0;
    int temp = arr[index];
    for(int i=0;i<1;i++){
        for(int j=i+1;j<size;j++){
            if(temp > arr[j])
                result = j;
        }
    }
    return result;
}
void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void selectionSort(int *arr, int size){
    int smallestElementIndex = 0;
    int result = 0;
    for(int i=1;i<size;i++){
        result = findSmallest(arr,size, smallestElementIndex);
        swap(arr, smallestElementIndex, result);
        smallestElementIndex++;
    }
    cout<<"Array after sorting : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter the size of yoyr array : ";
    cin>>size;
    int *arr = new int(size);
    cout<<"Enter the elememts of ypur array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    selectionSort(arr, size);
    return 0;
}