#include <iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of yoyr array : ";
    cin>>size;
    int *arr = new int(size);
    cout<<"Enter the elememts of ypur array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    return 0;
}