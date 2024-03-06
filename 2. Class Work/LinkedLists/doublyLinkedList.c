#include <stdio.h>
#include <malloc.h>
struct node {
    int data;
    struct node *prev, *next;
};
struct node* start = NULL;
struct node* end = NULL;
struct node* create_dll(struct node* start){
    struct node* newNode, *ptr;
    int data = 999;
    printf("Enter -1 to end\n");
    do{
        printf("Enter the data : ");
        scanf("%d",&data);
        newNode =  (struct node*)malloc(sizeof(struct node));
        if(start == NULL){
            newNode->data = data;
            start = end = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }else{
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = NULL;
            newNode->data = data;
            end = newNode;
        }
    } while(data != -1);
    return start;
}
struct node* insert_begi(struct node* start){
    struct node* newNode;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    newNode =  (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = start;
    start->prev = newNode;
    newNode->prev = NULL;
    start = newNode;
    printf("Node Inserted !!!");
    return start;
}
struct node* insert_end(struct node* start){
    struct node* newNode, *ptr;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    newNode =  (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    end->next = newNode;
    newNode->prev = end;
    newNode->next = NULL;
    end = newNode;
    printf("Node Inserted !!!");
    return start;
}
struct node* insert_before(struct node* start){
    struct node *newNode, *ptr;
    int data, value;
    printf("Enter the data : ");
    scanf("%d",&data);
    printf("Enter the data of the node before which newNode has to be inserted : ");
    scanf("%d",&value);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    ptr = start;
    if(ptr->data == value){
        ptr->prev = newNode;
        newNode->next = ptr;
        newNode->prev = NULL;
        start = newNode;
    }else{
            while(ptr->data != value){
            ptr = ptr->next;
        }
        newNode->prev = ptr->prev;
        newNode->next = ptr;
        ptr->prev = newNode;
        newNode->prev->next = newNode;
    }
    printf("Node Inserted !!!");
    return start;
    
}
struct node* insert_after(struct node* start){
    struct node *newNode, *ptr;
    int data, value;
    printf("Enter the data : ");
    scanf("%d",&data);
    printf("Enter the data of the node after which newNode has to be inserted : ");
    scanf("%d",&value);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    ptr =  start;
    if(end->data == value){
        end->next = newNode;
        newNode->prev = end;
        newNode->next = NULL;
        end = newNode;
    }else{
        while(ptr->data != value){
            ptr = ptr->next;
        }
        newNode->prev = ptr;
        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->next->prev = newNode;
    }
    printf("Node Inserted !!!");
    return start;
}
struct node* delete_begi(struct node* start){
    if(start->next == NULL){
        free(start);
        free(end);
        start = end = NULL;
    }else{
        struct node *ptr;
        ptr = start;
        start = ptr->next;
        start->prev = NULL;
        free(ptr);
    }
    printf("\nNode deleted !!!");
    return start;
}
struct node* delete_end(struct node* start){
    struct node *ptr;
    ptr = end;
    end = ptr->prev;
    end->next = NULL;
    free(ptr);
    printf("\nNode deleted !!!");
    return start;
}
struct node* delete_before(struct node* start){
    struct node *ptr;
    int value;
    printf("Enter the data of the node whose previous node has to be deleted : ");
    scanf("%d",&value);
    ptr = start;
    while(ptr->data != value){
        ptr = ptr->next;
    }
    if(ptr->prev == start){
        start = delete_begi(start);
    }else{
        ptr = ptr->prev;//To move to the node which has to be deleted 
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        printf("\nNode delete !!!");
    }
    return start;
}

struct node* delete_after(struct node* start){
    struct node *ptr;
    int value;
    printf("Enter the data of the node whose next node has to be deleted : ");
    scanf("%d",&value);
    ptr = start;
    while(ptr->data != value){
        ptr = ptr->next;
    }
    if(ptr->next == end){
        start = delete_end(start);
    }else{
        ptr = ptr->next;//To move to the node which has to be deleted 
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        free(ptr);
        printf("\nNode delete !!!");
    }
    return start;
}
struct node* display(struct node* start){
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
void delete_dll(struct node* start){
    while(start != NULL){
        start = delete_begi(start);
    }
    printf("DOUBLY LINKED LIST DELETED !!!");
}
int main(){
    int option;
    printf("********MENU*********\n");
    printf("1.  Create a Doubly Linked List\n");
    printf("2.  Insert at the beginning\n");
    printf("3.  Insert at the Last\n");
    printf("4.  Insert before\n");
    printf("5.  Insert after\n");
    printf("6.  Delete from the beginning\n");
    printf("7.  Delete from the last\n");
    printf("8.  Delete before X\n");
    printf("9.  Delete after X\n");
    printf("10. Display the List\n");
    do{
        printf("\nEnter your choice : ");
        scanf("%d",&option);
        switch(option){
        case 1: start = create_dll(start);
                printf("\nDOUBLY LINKED LIST CREATED ");
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
    delete_dll(start);
    return 0;
}