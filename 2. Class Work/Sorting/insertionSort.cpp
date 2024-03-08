#include <iostream>
using namespace std;
void insertionSort(int *arr, int size){
    int temp;
    int j;
    for(int i=1;i<size;i++){
        temp = arr[i];
        j = i-1;
        while((arr[j] > temp && (j>=0))){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    cout<<"Array after sorting : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter the size of your array : ";
    cin>>size;
    int *arr = new int(size);
    cout<<"Enter the elements of your array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    insertionSort(arr,size);
    return 0;
}