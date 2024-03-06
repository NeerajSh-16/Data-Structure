/*
    2) WAP to arrange a list of names in alphabetical order using pointer.
*/
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter how many numbers you want to in name list : ";
    cin>>num;
    string arr[num];
    cout<<"Enter the name in your list : ";
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    string *p = arr;
    for(int i=0;i<num;i++)
    {
        string name = arr[i];
        for(int j=i+1;j<num;j++)
        {
            if(arr[i][0] > arr[j][0])
            {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"List after sorting : ";
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
}