#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int d){
            this->data = d;
            this->next = NULL;
        }
};
node *start1 = NULL;
node *start2 = NULL;
node *start3 = NULL;
node* generateNumber(node* start){
    int data = 1;
    while(data){
        node *newNode, *ptr;
        cout<<"Enter digit : ";
        cin>>data;
        newNode = new node(data);
        if(data == -1) break;
        if(start == NULL){
            start = newNode;
        }else{
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    return start;
}
node* reverse(node* start){
    node* preptr = NULL;
    node* currptr = start;
    node* nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;
    }
    return preptr;
}
void insertNode(node* &ansHead, int data){
    node* newNode, *ptr;
    ptr = ansHead;
    newNode = new node(data);
    if(ansHead == NULL){
        ansHead = newNode;
    }else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}
node* addTwoNumbers(node* first, node* second){
    int sum = 0;
    int carry = 0;
    node* ansHead = NULL;
    while(first != NULL ||second != NULL || carry != 0){
        sum = carry;
        if(first != NULL){
            sum += first->data;
            first = first->next;
        }
        if(second != NULL){
            sum += second->data;
            second = second->next;
        }
        int digit = sum%10;
        carry = sum/10;
        insertNode(ansHead, digit);
    }
    return ansHead;
}
void display(node* start){
    node* ptr = start;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
node* add(node* first, node* second){
    first = reverse(first);
    second = reverse(second);
    node* ans = addTwoNumbers(first, second);
    ans = reverse(ans);
    return ans;
}
int main(){
    start1 = generateNumber(start1);
    start2 = generateNumber(start2);
    cout<<"\n1st number : ";
    display(start1);
    cout<<"\n2nd Number : ";
    display(start2);
    start3 = add(start1, start2);
    cout<<"\nAfter addition : ";
    display(start3);
    return 0;
}