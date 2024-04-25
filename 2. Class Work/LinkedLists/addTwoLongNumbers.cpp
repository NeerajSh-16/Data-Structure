#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* start1 = NULL;
struct node* end1 = NULL;
struct node* start2 = NULL;
struct node* end2 = NULL;
struct node* start3 = NULL;
struct node* end3 = NULL;

struct node* create_Long_integer(struct node* start, struct node* end, int codex){
    struct node* newNode, *ptr;
    int data = 999;
    printf("Enter -1 to end\n");
    while(data){
        printf("Enter the data : ");
        scanf("%d",&data);
        if(data == -1){
            break;
        }
        newNode =  (struct node*)malloc(sizeof(struct node));
        if(end == NULL){
            newNode->data = data;
            start = end = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }else{
            ptr = end;
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = NULL;
            newNode->data = data;
            end = newNode;
        }
    }
    if(codex == 1){
        start1 = start;
        end1 = end;
    }else if(codex == 2){
        start2 = start;
        end2 = end;
    }
    cout<<"Data at last node : "<<end->data<<"\n";
    return start;
}
struct node* display(struct node* start){
    struct node* ptr;
    ptr = start;
    while(ptr != NULL){// TO THINK why are we not using ptr->next != NULL here (I guess its related to create_poly function)
        printf("%d",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}
struct node* add_node(struct node* start, struct node* end, int data){
    struct node* newNode, *ptr;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(end == NULL && start == NULL){
        start = end = newNode;
        newNode->next = NULL;
        newNode->prev= NULL;
    }else{
        ptr = start;
        ptr->prev = newNode;
        newNode->prev = NULL;
        newNode->next = ptr;
        start = newNode;
    }
    cout<<"(inside function) Data at start node : "<<start->data<<"\n";
    return start;
}
struct node* add_long_number(struct node* end1, struct node* end2, struct node* end3, struct node* start){
    struct node *newNode, *ptr1, *ptr2, *ptr3;
    ptr1 = end1;
    ptr2 = end2;
    ptr3 = end3;
    int sum, carry = 0;
    cout<<"Outisde While \n";
    cout<<ptr1->data<<"\n";
    while(ptr1 != NULL && ptr2 != NULL){
        sum = ptr1->data + ptr2->data + carry;
        if(sum <= 9){
            start3 = add_node(start3, end3, sum);
            carry = 0;
            cout<<"Inside IF \n";
        }else{
            int base_number = (ptr1->data + ptr2->data) % 10;
            start3 = add_node(start3, end3, base_number + carry);
            carry = (ptr1->data + ptr2->data) / 10;
            if(ptr1->prev == NULL && ptr2->prev == NULL){
                start3 = add_node(start3, end3, carry);
            }
            cout<<"Inside ELSE \n";
        }
        ptr1 = ptr1->prev;
        ptr2 = ptr2->prev;
    }
    cout<<"Data at start node : "<<start3->data<<"\n";
    return start3;
}
struct node* delete_begi(struct node* start){
    struct node* ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
void delete_number(struct node* start){
    struct node* ptr = start;
    while(ptr != NULL){
        start = delete_begi(start);
    }
}
int main(){
    printf("*********MENU********");
    printf("\n1. Create 1st Long Number");
    printf("\n2. Create 2nd Long Number");
    printf("\n3. Add the Long Numbers");
    printf("\n4. Display th result\n");
    int choice;
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice != 5){
        switch(choice){
            case 1: start1 = create_Long_integer(start1, end1, 1);
                    printf("1st Polynomial : ");
                    start1 = display(start1);
                    break;
            case 2: start2 = create_Long_integer(start2, end2, 2);
                    printf("2nd Polynomial : ");
                    start2 = display(start2);
                    break;
            case 3: start3 = add_long_number(end1, end2, end3, start3);
                    printf("Addition Performed\n");
                    break;
            case 4: printf("New Long Number : ");
                    start3 = display(start3);
                    break;
        }
        printf("Enter your choice (5 to EXIT): ");
        scanf("%d",&choice);
    }
    if(start1 != NULL) delete_number(start1);
    if(start2 != NULL) delete_number(start2);
    if(start3 != NULL) delete_number(start3);
    return 0;
}