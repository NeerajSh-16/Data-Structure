#include <iostream>
using namespace std;
class node{
    public:
        int degree, coefficient;
        node *next;
        node(int c, int d){
            this->coefficient = c;
            this->degree = d;
            this->next = NULL;
        }
};
node *START1 = NULL;
node *START2 = NULL;
node *START3 = NULL;
node* generatePolynomial(node* start){
    int data = 1, degree = 1;
    while(data){
        node *newNode, *ptr;
        cout<<"Enter coefficient : ";
        cin>>data;
        cout<<"Enter Degree : ";
        cin>>degree;
        newNode = new node(data, degree);
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
node* addNode(node *start, int data, int degree){
    node *newNode, *ptr;
    ptr = start;
    newNode = new node(data, degree);
    if(start == NULL){
        start = newNode;
    }else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return start;
}
node* addTwoPolynomial(node* start1, node* start2, node* start3){
    node *ptr1 = start1, *ptr2 = start2;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->degree == ptr2->degree){
            int sum = ptr1->coefficient + ptr2->coefficient;
            cout<<"Sum of new Node : "<<sum<<"\n";
            start3 = addNode(start3, sum, ptr1->degree);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->degree > ptr2->degree){
            cout<<"Inside 1st ELSE IF\n";
            start3 = addNode(start3, ptr1->coefficient, ptr1->degree);
            ptr1 = ptr1->next;
        }else if(ptr2->degree > ptr1->degree){
            cout<<"INSIDE 2nd ELSE IF\n";
            start3 = addNode(start3, ptr2->coefficient, ptr2->degree);
            ptr2 = ptr2->next;
        }
    }
    // Add remaining nodes from start1
    while(ptr1 != NULL){
        start3 = addNode(start3, ptr1->coefficient, ptr1->degree);
        ptr1 = ptr1->next;
    }
    // Add remaining nodes from start2
    while(ptr2 != NULL){
        start3 = addNode(start3, ptr2->coefficient, ptr2->degree);
        ptr2 = ptr2->next;
    }
    return start3;
}

node* printPolynomial(node* start){
    node *ptr = start;
    while(ptr != NULL){
        cout<<ptr->coefficient;
        if(ptr->degree > 0){
            cout<<"(x^"<<ptr->degree<<")";
        }
        if(ptr->next !=NULL) cout<<" + ";
        ptr = ptr->next;
    }
    cout<<endl;
    return start;
}
int main(){
    cout<<"Enter 1st Polynomial : \n";
    START1 = generatePolynomial(START1);
    cout<<"Enter 2nd Polynomial : \n";
    START2 = generatePolynomial(START2);
    START3 = addTwoPolynomial(START1, START2, START3);
    cout<<"1st Polynomial : ";
    START1 = printPolynomial(START1);
    cout<<"2nd Polynomial : ";
    START2 = printPolynomial(START2);
    cout<<"After ADDITION : ";
    START3 = printPolynomial(START3);
    return 0;
}