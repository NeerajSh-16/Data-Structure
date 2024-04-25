#include <stdio.h>
#define MAX 10
int qu[MAX], frontA = -1, frontB = MAX, rearA = -1, rearB = MAX;
void enqueA(int x){
    if(rearA == rearB -1){
        printf("A Overflow \n");
    }else if(frontA == -1 && rearA == -1){
        frontA = rearA = 0;
        qu[rearA] = x;
    }else{
        rearA++;
        qu[rearA] = x;
    }
}
void enqueB(int x){
    if(rearB - 1 == rearA){
        printf("B Overflow \n");
    }else if(frontB == MAX && rearB == MAX){
        frontB = rearB = MAX-1;
        qu[rearB] = x;
    }else{
        rearB--;
        qu[rearB] = x;
    }
}
int dequeA(){
    if(frontA == -1 || frontA > rearA){
        printf("A underflow \n");
        return -1;
    }else if(frontA == rearA){
        int x = qu[frontA];
        frontA = rearA = -1;
        return x;
    }else{
        int x = qu[frontA];
        frontA++;
        return x;
    }
}
int dequeB(){
    if(rearB - 1 == rearA){
        printf("B Underflow \n");
    }else if(frontB == rearB){
        int x = qu[frontB];
        frontB = rearB = MAX;
        return x;
    }else{
        int x = qu[frontB];
        frontB--;
        return x;
    }
}
void displayA(){
    if(frontA == -1 && rearA == -1){
        printf("A is Empty \n");
    }else{
        for(int i=frontA;i<=rearA;i++){
            printf("%d ",qu[i]);
        }printf("\n");
    }
}
void displayB(){
    if(frontB == -1 && rearB == -1){
        printf("B is Empty \n");
    }else{
        for(int i=frontB;i>=rearB;i--){
            printf("%d ",qu[i]);
        }printf("\n");
    }
}
int main(){
    int choice, x;
    printf("*****MENU*****\n");
    printf("1. Insert in A\n");
    printf("2. Delete from A\n");
    printf("3. Display A\n");
    printf("4. Insert in B\n");
    printf("5. Delete from B\n");
    printf("6. Display B\n");
    printf("7. EXIT \n");
    do{
        printf(" Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element : ");
                    scanf("%d",&x);
                    enqueA(x);
                    break;
            case 2: x = dequeA();
                    printf("%d is removed from A\n",x);
                    break;
            case 3: printf("Your Queue A : ");
                    displayA();
                    break;
            case 4: printf("Enter the element : ");
                    scanf("%d",&x);
                    enqueB(x);
                    break;
            case 5: x = dequeB();
                    printf("%d is removed from B\n",x);
                    break;
            case 6: printf("Your Queue B : ");
                    displayB();
        }
    }while(choice != 7);
    return 0;

}
