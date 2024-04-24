#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};
node *START1 = NULL;
node *START2 = NULL;
node *START3 = NULL;
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
node* reverse(node *start){
    node *prevptr = NULL;
    node *currptr = start;
    node *nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;//pointing to next node
        currptr->next = prevptr;//pointing to previous node

        prevptr = currptr;//moving one node ahead
        currptr = nextptr;//moving one nide ahead
    }
    return prevptr;
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
node* add(node* first, node* second){
    int carry = 0;
    node* ansHead = NULL;
    while(first != NULL || second != NULL || carry != 0){
        int sum = carry;
        if(first != NULL){
            sum += first->data;
            first = first->next;
        }
        if(second != NULL){
            sum += second->data;
            second = second->next;
        }
        int digit = sum % 10;
        int carry = sum / 10;
        insertNode(ansHead, digit);
    }
    return ansHead;
}
node* addTwoNumbers(node *first, node *second){
    first = reverse(first);
    second = reverse(second);

    node *ans = add(first, second);
    ans = reverse(ans);
    return ans;
}
node* display(node* start){
    node* ptr = start;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    return start;
}
int main(){
    cout<<"\nEnter 1st number : ";
    START1 = generateNumber(START1);

    cout<<"\n1st number : ";
    START1 = display(START1);

    cout<<"\nEnter 2nd number : ";
    START2 = generateNumber(START2);

    cout<<"\n2nd Number : ";
    START2 = display(START2);

    START3 = addTwoNumbers(START1, START2);

    cout<<"\nAfter Addition : ";
    START3 = display(START3);
    return 0;
}