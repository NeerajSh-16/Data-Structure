#include <stdio.h>
#define MAX 6
int qu[MAX], front = -1, rear = -1;
void enqueue(int data){
    if(rear == MAX -1){
        printf("Queue is Full \n");
    }else if(front == -1 || rear == -1 ){
        front = rear = 0;
        qu[rear] = data;
    }else{
        rear++;
        qu[rear] = data;
    }
}
int deque(){
    if(front == -1 || front > rear){
        printf("Queue Underflow \n");
        return -1;
    }else{
        int x = qu[front];
        front++;
        if(front > rear){
            front = rear = -1;
        }
        return x;
    }
}
int peek(){
    if(front == -1 || front > rear){
        printf("Queue is Empty \n");
    }else{
        return qu[front];
    }
}
void display(){
    if(front == -1 || front > rear){
        printf("Queue is Emoty \n");
    }else{
        for(int i=front;i<=rear;i++){
            printf("%d ",qu[i]);
        }printf("\n");
    }
}
int main(){
    int choice, x;
    printf("*****Menu*****\n");
    printf("1. Push\n");
    printf("2, Pop\n");
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