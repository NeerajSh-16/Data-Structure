#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node* next;
};
struct node* start = NULL;
struct node* create_sll(struct node* start)
{
    struct node *newNode, *ptr;
    int num;
    printf("Enter -1 to end\n");
    while(num != -1){
        printf("Enter the data : ");
        scanf("%d",&num);
        newNode =  (struct node*)malloc(sizeof(struct node));
        newNode->data = num;
        if(start == NULL){
            newNode->next = NULL;
            start = newNode;
        }
        else{
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }
    }
    return start;
}
struct node* insert_begi(struct node* start){
    struct node *newNode;
    int data;
    printf("Enter the data : \n");
    scanf("%d",&data);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data =  data;
    newNode->next = start;
    start = newNode;
    return start;
}
struct node* insert_end(struct node* start){
    struct node *newNode, *ptr;
    int num;
    printf("Enter the data : \n");
    scanf("%d",&num);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return start;
}
struct node* insert_before(struct node* start){
    struct node *newNode, *ptr, *preptr;
    int data, value;
    printf("Enter the data : \n");
    scanf("%d",&data);
    printf("Enter the value before which new node has to be inserted : ");
    scanf("%d",&value);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    ptr = start;
    while(ptr->data != value){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return start;
}
struct node* insert_after(struct node* start){
    struct node *newNode, *ptr, *preptr;
    int data, value;
    printf("Enter the data : \n");
    scanf("%d",&data);
    printf("Enter the value after which new node has to be inserted : ");
    scanf("%d",&value);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    ptr = start;
    preptr = ptr;
    while(preptr->data != value){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
    return start;
}
struct node* delete_begi(struct node* start){
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node* delete_end(struct node* start){
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node* delete_before(struct node* start){
    struct node *ptr, *preptr;
    int value;
    printf("Enter the value before which the node has to be deleted : ");
    scanf("%d",&value);
    ptr = start;
    if(ptr->data == value){//To check if we are deleting our first node
        start = delete_begi(start);
        return start;
    }else{
        while(ptr->data != value){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}
struct node* delete_after(struct node* start){
    struct node *ptr, *preptr;
    int value;
    printf("Enter the value after which the node has to be deleted : ");
    scanf("%d",&value);
    ptr = start;
    preptr = ptr;
    if(ptr->data == value){
        ptr = ptr->next;
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }else{
        while(preptr->data != value){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}
struct node* display(struct node* start){
    struct node* ptr;
    ptr = start;
    while(ptr->next != NULL){
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    return start;
}
int main(){
    int option;
    printf("********MENU*********\n");
    printf("1. Create a Singly Linked List\n");
    printf("2. Insert at the beginning\n");
    printf("3. Insert at the Last\n");
    printf("4. Insert before\n");
    printf("5. Insert after\n");
    printf("6. Delete from the beginning\n");
    printf("7. Delete from the last\n");
    printf("8. Delete before X\n");
    printf("9. Delete after X\n");
    printf("10. Display the List\n");
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&option);
        switch(option){
        case 1: start = create_sll(start);
                printf("LINKED LIST CREATED \n\n");
                break;
        case 2: start = insert_begi(start);
                break;
        case 3: start = insert_end(start);
                break;
        case 4: start = insert_before(start);
                break;
        case 5: start = insert_after(start);
                break;
        case 6: start = delete_begi(start);
                break;
        case 7: start = delete_end(start);
                break;
        case 8: start = delete_before(start);
                break;
        case 9: start = delete_after(start);
                break;
        case 10: start = display(start);
                break;
        }
    }while(option != 11);
    return 0;
}