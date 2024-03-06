#include <iostream>
using namespace std;
void printer(int **arr, int a, int b)
{
    for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
}
int main(){
    int arr[2][2] = {{1,2},{3,4}};
    printer(arr[][2],2,2);
}