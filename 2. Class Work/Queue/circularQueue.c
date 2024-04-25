#include <stdio.h>
#define MAX 6
int qu[MAX], front = -1, rear = -1;
void enqueue(int x){
    if((rear + 1)%MAX == front){
        printf("OVERFLOW \n");
    }else if(front == -1 && rear == -1){
        front = rear = 0;
        qu[rear] = x;
    }else{
        rear = (rear + 1)%MAX;
        qu[rear] = x;
    }
}
int deque(){
    if(front == -1 && rear == -1){
        printf("UNDERFLOW \n");
        return -1;
    }else if(front == rear){// Only 1 element left
        int x = qu[front];
        front = rear = -1;
        return x;
    }else{
        int x = qu[front];
        front = (front + 1)%MAX;
        return x;
    }
}
void display(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty \n");
    }else{
        if(front < rear){
            for(int i=front;i<=rear;i++){
                printf("%d ",qu[i]);
            }
        }else{
            for(int i=front;i<MAX;i++){
                printf("%d ",qu[i]);
            }
            for(int i=0;i<=rear;i++){
                printf("%d ",qu[i]);
            }
        }
    }
}
int peek(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty \n");
        return -1;
    }else{
        return qu[front];
    }
}
int main(){
    int choice, x;
    printf("*****Menu*****\n");
    printf("1. Insert\n");
    printf("2, Delete\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Stop the program \n");
    do{
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter element : ");
                    scanf("%d", &x);
                    enqueue(x);
                    break;
            case 2: x = deque();
                    printf("%d is removed \n", x);
                    break;
            case 3: x = peek();
                    printf("%d is at the front \n", x);
                    break;
            case 4: printf("Your QUEUE : ");
                    display();
        }
    }while(choice != 5);
    return 0;
}