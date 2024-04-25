#include <iostream>
using namespace std;

void rotate(int arr[], int n){
    int temp = arr[0];
    arr[0] = arr[n-1];
    for(int i=1;i<n;i++){
        int temp2 = arr[i];
        arr[i] = temp;
        temp = temp2;
    }
}
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array before Rotation : ";
    printArray(arr, n);
    rotate(arr, n);
    printArray(arr, n);
    return 0;
}