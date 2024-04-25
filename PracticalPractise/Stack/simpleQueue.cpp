#include <iostream>
using namespace std;
#define MAX 10
int front = -1;
int rear = -1;
int qu[MAX];
void enqueue(int data){
    if(rear == -MAX-1){
        cout<<"\nOverflow ";
    }else if(front == -1 || front > rear){
        front = rear = 0;
        qu[rear] = data;
    }else{
        rear++;
        qu[rear] = data;
    }
}
int deque(){
    int x = -1;
    if(front == -1){
        cout<<"Underflow\n";
    }else{
        x = qu[front];
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }
    return x;
}
void display(){
    if(front == -1 || front > rear){
        printf("Queue is Emoty \n");
    }else{
        for(int i=front;i<=rear;i++){
           cout<<qu[i]<<" ";
        }
    }
}
int main(){
    int x;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    x = deque();
    x = deque();
    cout<<"\n";
    display();
    return 0;
}