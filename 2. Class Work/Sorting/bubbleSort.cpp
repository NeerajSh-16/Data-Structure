#include <iostream>
using namespace std;
void bubbleSort(int *arr, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"Array after sorting : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int *arr = new int(size);
    cout<<"Enter the elements of your array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    bubbleSort(arr, size);
    return 0;
}