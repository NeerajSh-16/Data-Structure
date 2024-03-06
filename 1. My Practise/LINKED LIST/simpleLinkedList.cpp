#include<iostream>
using namespace std;
class node{
    public:
        node* next;
        int data;
        node();
        node(int x);

};
node :: node(){
    next = NULL;
    data = 0;
}
node :: node(int x){
    data = x;
    next = NULL;
}
class LinkedList{
    public:
        node* start;
        LinkedList();
        void insertFront(int x);
        void insertLast(int x);
        void insertBefore(int x);
        void insertAfter(int x);
        void display();

};
LinkedList :: LinkedList(){
    start = NULL;
}
void LinkedList :: insertFront(int x){
    node* newNode = new node(x);
    start = newNode;
}
void LinkedList :: insertLast(int x){
    node* newNode = new node(x);
    if(start == NULL){
        start = newNode;
        return;
    }
    node* temp = start;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    
}
void LinkedList :: insertBefore(int x){
    node* temp, *pretemp;
    node* newNode = new node(x);
    temp = start;
    while(temp->data != x){
        pretemp = temp;
        temp = temp->next;
    }
    pretemp->next = newNode;
    newNode->next = temp;

}
void LinkedList :: insertAfter(int x){
    node* temp, *pretemp;
    node* newNode = new node(x);
    temp = start;
    while(pretemp->data != x){
        pretemp = temp;
        temp = pretemp->next;
    }
    pretemp->next = newNode;
    newNode->next = temp;
}
void LinkedList :: display(){
    node* temp = start;
    cout<<"Linked List : ";
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
}
int main(){
    LinkedList ll;
    ll.insertLast(1);
    ll.insertLast(2);
    ll.insertLast(3);
    ll.insertLast(4);
    ll.insertLast(5);
    ll.display();
    return 0;
}