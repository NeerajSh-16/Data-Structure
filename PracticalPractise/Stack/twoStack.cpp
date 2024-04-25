#include <iostream>
using namespace std;
#define MAX 10
int topA = -1, topB = MAX;
int stk[MAX];
void pushA(int data){
    if(topA == topB-1){
        cout<<"Stack A Overflow\n";
    }else{
        topA++;
        stk[topA] = data;
    }
}
void pushB(int data){
    if(topA == topB-1){
        cout<<"Stack B Overflow\n";
    }else{
        topB--;
        stk[topA] = data;
    }
}
int popA(){
    if(topA == -1){
        cout<<"Stack A Underflow\n";
    }else{
        int x = stk[topA];
        topA--;
        return x;
    }
}
int popB(){
    if(topB == MAX-1){
        cout<<"Stack B Underflow\n";
    }else{
        int x = stk[topB];
        topA++;
        return x;
    }
}
int peekA(){
    if(topA == -1){
        printf("Stack is Empty \n");
    }else{
        return stk[topA];
    }
}
int peekB(){
    if(topB == MAX){
        printf("Stack B is Empty \n");
        return -1;
    }else{
        return stk[topB];
    }
}
void displayA(){
    if(topA == -1){
        cout<<"Stack A Underflow\n";
    }else{
        for(int i=topA;i>=0;i--){
            cout<<stk[i]<<" ";
        }
    }
}
void displayB(){
    if(topB == MAX-1){
        cout<<"Stack B Underflow\n";
    }else{
        for(int i=topB;i<MAX;i++){
            cout<<stk[i]<<" ";
        }
    }
}
int main(){
    
    int choice, x;
    printf("*****MENU*****\n");
    printf("1. Push in A\n");
    printf("2. Pop from A\n");
    printf("3. Peek in A\n");
    printf("4. Display A\n");
    printf("5. Push in B\n");
    printf("6. Pop from B\n");
    printf("7. Peek in A\n");
    printf("8. Display B\n");
    printf("\n Enter 9 to stop \n");
    do{
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter element : ");
                    scanf("%d", &x);
                    pushA(x);
                    break;
            case 2: x = popA();
                    printf("%d is poped from stack A\n", x);
                    break;
            case 3: x = peekA();
                    printf("%d is at the top of the stack A\n", x);
                    break;
            case 4: printf("Your STACK : ");
                    displayA();
                    break; 
            case 5: printf("Enter element : ");
                    scanf("%d", &x);
                    pushB(x);
                    break;
            case 6: x = popB();
                    printf("%d is poped from stack B\n", x);
                    break;
            case 7: x = peekB();
                    printf("%d is at the top of the stack B\n", x);
                    break;
            case 8: printf("Your STACK : ");
                    displayB();
                    break;
        }
    }while(choice != 9);
    return 0;
}