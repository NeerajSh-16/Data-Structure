#include <iostream>
using namespace std;
#define MAX 10
int front = -1;
int rear = -1;
int qu[MAX];
void enque(int data){
    if(rear == MAX - 1){
        cout<<"\nUnderflow";
    }else if(front == -1 || front > rear){
        front = rear = 0;
        qu[rear] = data;
    }else{
        rear = (rear + 1)%MAX;
        qu[rear] = data;
    }
}
int deque(){
    int x = -1;
    if(front == -1 && rear == -1){
        cout<<"Underflow\n";
    }else if(front == rear){
        x = qu[front];
        front = rear = -1;
    }else{
        x = qu[front];
        front = (front + 1)%MAX;
    }
    return x;
}