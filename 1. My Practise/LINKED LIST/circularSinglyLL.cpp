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
        void insert(int x);
        void display();

};
LinkedList :: LinkedList(){
    start = NULL;
}
void LinkedList :: insert(int x){
    node* newNode = new node(x);
    if(start == NULL){
        start = newNode;
        start->next=start;
        return;
    }
    node* temp = start;
    while(temp->next != start)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = start;
    
}
void LinkedList :: display(){
    node* temp = NULL;
    //node* temp2 = start;
    cout<<"Circular Linked List : ";
    do{
        if(temp==NULL){
            temp=start;
        }
        cout<<start->data<<"-> ";
        start = start->next;
    }while(temp != start);
    cout<<temp->data<<"-> ";
}
int main(){
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.display();
    return 0;
}