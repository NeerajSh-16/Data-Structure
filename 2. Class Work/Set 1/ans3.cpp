/*
    3) WAP to add/multiply two matrices using array of pointers.
*/
#include <iostream>
using namespace std;
int main()
{
    int a,b,n,m;
    cout<<"Enter the dimension of first matrix : ";
    cin>>a>>b;
    int **arr = new int*[a];
    cout<<"Enter the elements of your matrix : \n";
    for(int i=0;i<a;i++)
    {
        arr[i] = new int[b];
        for(int j=0;j<b;j++)
        {
            cin>>arr[i][j];
        }
    }
    
        cout<<"Your 1st matrix : \n";
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    cout<<"\nEnter the dimensuons of second matrix : ";
    cin>>m>>n;
    int **brr = new int*[m];
    cout<<"Enter the elements of your matrix : \n";
    for(int i=0;i<m;i++)
    {
        brr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>brr[i][j];
        }
    }
    cout<<"Your 2nd matrix : \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<brr[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    int crr[a][b];
    for(int i=0;i<a;i++)
    {
        for(int j=0;i<b;j++)
        {
            crr[i][j] = 0;
            crr[i][j] += arr[i][j]*brr[i][j];
        }
    }
    cout<<"Your Addition matrix : \n";
    for(int i=0;i<b;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<crr[i][j]<<" ";
        }
        cout<<"\n";
    }
    if(b != m) cout<<"Matrix multiplication is not possible";
    else
    {
       /*
        int **crr = new int*[b];
        for(int i=0;i<b;i++)
        {
            crr[i] = new int[m];
        }
        */
        int drr[b][n];
        for(int i=0;i<a;i++)
        {
            for(int j=0;i<n;j++)
            {
                drr[i][j] = 0;
                for(int k=0;k<b;k++)
                {
                    drr[i][j] += arr[i][k]*brr[k][j];
                }
            }
        }
        cout<<"Your multiplied matrix : \n";
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<b;j++)
            {
                cout<<drr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
