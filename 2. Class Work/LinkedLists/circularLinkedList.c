#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node* create_cll(struct node* start){
    struct node *newNode;
    int data = 999;
    do{
        printf("Enter the data : ");
        scanf("%d",&data);
        newNode = (struct node*)malloc(sizeof(struct node));
        if(start == NULL){
            start = newNode;
            newNode->next = newNode;
            newNode->data = data;
        }else{
            if(data == -1)
                break;
            struct node *ptr;
            ptr = start;
            while(ptr->next != start){
                ptr = ptr->next;
            }
            newNode->data = data;
            ptr->next = newNode;
            newNode->next = start;
        }
    }while(data != -1);
    return start;
}
struct node* insert_begi(struct node* start){
    struct node* newNode, *ptr;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = start;
    start = newNode;
    return start;
}
struct node* insert_end(struct node* start){
    struct node* newNode, *ptr;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = start;
    return start;
}
struct node* delete_begi(struct node* start){
    struct node* ptr;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = start->next;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node* delete_end(struct node* start){
    struct node* ptr, *preptr;
    ptr = start;
    while(ptr->next != start){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;//Be Careful
    free(ptr);
    return start;
}
struct node* display(struct node* start){
    struct node* ptr;
    ptr = start;
    while(ptr->next != start){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr -> data);//Tricky Line
    return start;
}
void delete_cll(struct node* start){
    struct node* ptr;
    ptr = start;
    while(ptr->next != start)
        start = delete_end(start);
    free(start);
}
int main(){
    int option;
    printf("********MENU*********\n");
    printf("1.  Create a Circular Linked List\n");
    printf("2.  Insert at the beginning\n");
    printf("3.  Insert at the Last\n");
    printf("4.  Delete from the beginning\n");
    printf("5.  Delete from the last\n");
    printf("6.  Display the List\n");
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&option);
        switch(option){
        case 1: start = create_cll(start);
                printf("\nDOUBLY LINKED LIST CREATED ");
                break;
        case 2: start = insert_begi(start);
                break;
        case 3: start = insert_end(start);
                break;
        case 4: start = delete_begi(start);
                break;
        case 5: start = delete_end(start);
                break;
        case 6: start = display(start);
                break;
        }
    }while(option != 7);
    delete_cll(start);
    return 0;
}
