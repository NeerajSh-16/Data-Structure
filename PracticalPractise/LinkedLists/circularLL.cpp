#include <iostream>
using namespace std;
class node{
    public  :
        int data;
        node *next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};
node *start = NULL;
node* display(node* start);
node* createCLL(node* start){
    node *newNode, *ptr;
    int data = 1;
    while(data){
        cout<<"Enter data : ";
        cin>>data;
        newNode = new node(data);
        if(data == -1) break;
        if(start == NULL){
            newNode->next = newNode;
            start = newNode;
        }else{
            ptr = start;
            while(ptr->next != start){
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = start;
        }
    }
    return start;
}
node* insert_begi(node* start){
    node* ptr = start;
    node* newNode;
    int data;
    cout<<"Enter data : ";
    cin>>data;
    while(ptr->next != start)
        ptr = ptr->next;
    newNode = new node(data);
    newNode->next = start;
    ptr->next = newNode;
    start = newNode;
    return start;
}
node* delete_begi(node* start){
    node* ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
    ptr->next = start->next;
    ptr = start;
    start = start->next;
    delete(ptr);
    return start;
}
node* insert_end(node* start){
    node* newNode, *ptr;
    int data;
    cout<<"Enter data : ";
    cin>>data;
    ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
    newNode = new node(data);
    ptr->next = newNode;
    newNode->next = start;
    return start;
}
node* delete_end(node* stafrt){
    node* ptr = start;
    node* preptr;
    while(ptr->next != start){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    delete(ptr);
    return start;
}
node* display(node* start){
    node* ptr = start;
    while(ptr->next != start){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<ptr->data;
    return start;
}
int main(){

    start = createCLL(start);
    cout<<"Circular Linked List : ";
    start = display(start);
    cout<<"\nInsert Front : ";
    start = insert_begi(start);
    start = display(start);
    cout<<"\nDelete Front : ";
    start = delete_begi(start);
    start = display(start);
    cout<<"\nInsert END : ";
    start = insert_end(start);
    start = display(start);
    cout<<"\nDelete END : ";
    start = delete_end(start);
    start = display(start);
    return 0;
}