//GO TO DISPLAY FUNCTION IMMEDIATELY
#include <stdio.h>
#include <malloc.h>
struct node{
    int degree, coefficient;
    struct node* next;
};
struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* start3 = NULL;
struct node* start4 = NULL;
struct node* create_poly(struct node* start){
    struct node* newNode, *ptr;
    int degree, coeffeicient;
    printf("Enter the degree and its coeffiecient : ");
    scanf("%d %d",&degree, &coeffeicient);
    while(degree != -1 && coeffeicient != -1){
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->coefficient = coeffeicient;
        newNode->degree = degree;
        newNode->next = NULL;
        if(start == NULL){
            start = newNode;
        }else{
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        printf("Enter the degree and its coeffiecient : ");
        scanf("%d %d",&degree, &coeffeicient);
    }
    return start;
}
struct node* add_node(struct node* start,int coefficient, int degree){
    struct node* newNode, *ptr;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->degree = degree;
    newNode->coefficient = coefficient;
    newNode->next = NULL;
    if(start == NULL){
        start = newNode;
    }else{
        ptr = start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return start;
}
struct node* add_poly(struct node* start, struct node* start2, struct node* start3){
    struct node *newNode, *ptr1, *ptr2, *ptr3;
    ptr1 = start1;
    ptr2 = start2;
    ptr3 = start3;
    int sum;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->degree == ptr2->degree){
            sum = ptr1->coefficient + ptr2->coefficient;
            start3 = add_node(start3,sum,ptr1->degree);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }else if(ptr1->degree > ptr2->degree){
            start3 = add_node(start3,ptr1->coefficient, ptr1->degree);
            ptr1 = ptr1->next;
        }else if(ptr2->degree > ptr1->degree){
            start3 = add_node(start3,ptr2->coefficient,ptr2->degree);
            ptr2 = ptr2->next;
        }
    }
    return start3;
}
struct node* display(struct node* start){
    struct node* ptr;
    ptr = start;
    while(ptr != NULL){// TO THINK why are we not using ptr->next != NULL here (I guess its related to create_poly function)
        printf("%d(x^%d) ",ptr->coefficient,ptr->degree);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}
struct node* delete_begi(struct node* start){
    struct node* ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
void delete_poly(struct node* start){
    struct node* ptr;
    while(ptr != NULL){
        start = delete_begi(start);
    }
}
int main(){
    printf("*********MENU********");
    printf("\n1. Create 1st Polynomial");
    printf("\n2. Create 2nd Polynomial");
    printf("\n3. Add the Polynoials");
    printf("\n4. Display th result\n");
    int choice;
    printf("Enter your choice : ");
    scanf("%d",&choice);
    while(choice != 5){
        switch(choice){
            case 1: start1 = create_poly(start1);
                    printf("1st Polynomial : ");
                    start1 = display(start1);
                    break;
            case 2: start2 = create_poly(start2);
                    printf("2nd Polynomial : ");
                    start2 = display(start2);
                    break;
            case 3: start3 = add_poly(start1, start2, start3);
                    printf("Addition Performed");
                    break;
            case 4: printf("New Polynomial : ");
                    start3 = display(start3);
                    break;
        }
        printf("Enter your choice : ");
        scanf("%d",&choice);
    }
    if(start1 != NULL) delete_poly(start1);
    if(start2 != NULL) delete_poly(start2);
    if(start3 != NULL) delete_poly(start3);
    return 0;
}