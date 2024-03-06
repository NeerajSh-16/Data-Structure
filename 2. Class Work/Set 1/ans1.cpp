/*
    1) WAP to find the mean and standard deviation of a list of given numbers using pointer.
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num;
    float sum = 0, square_sum = 0, std = 0;
    cout<<"Enter how many numbers you want to enter in your list : ";
    cin>>num;
    int arr[num];
    cout<<"Enter the numbers of youyr list : ";
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    int *p = arr;
    for(int i=0;i<num;i++)
    {
        sum += *(p + i);
        square_sum += pow(*(p + i),2);
    }
    float mean = sum/num;
    cout<<"Square Sum : "<<square_sum<<"\n";
    cout<<"Mean : "<<mean<<"\n";
    cout<<"standard Deviation : "<<(square_sum)/num-pow(mean,2);
}