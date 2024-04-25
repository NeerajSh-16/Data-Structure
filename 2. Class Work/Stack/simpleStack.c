#include <stdio.h>
#define MAX 6
int stk[MAX], top = -1;
void push(int data){
    if(top == MAX-1){
        printf("Stack Overflow \n");
        return;
    }else{
        top++;
        stk[top] = data;
        return;
    }
}
int pop(){
    if(top == -1){
        printf("Stack Underflow \n");
        return -1;
    }else{
        int x = stk[top];
        top--;
        return x;
    }
}
int peek(){
    if(top == -1){
        printf("Stack is Empty \n");
    }else{
        return stk[top];
    }
}
void display(){
    if(top == -1){
        printf("Stack is Empty \n");
    }else{
        for(int i = top; i>=0; i--){
            printf("%d ",stk[i]);
        }
    }
}
int main(){
    int choice, x;
    printf("*****MENU*****\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("\n Enter 5 to stop \n");
    do{
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter element : ");
                    scanf("%d", &x);
                    push(x);
                    break;
            case 2: x = pop();
                    printf("%d is poped from stack \n", x);
                    break;
            case 3: x = peek();
                    printf("%d is at the top of the stack\n", x);
                    break;
            case 4: printf("Your STACK : ");
                    display();
                    break;
        }
    }while(choice != 5);
    return 0;
}