#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node *prev, *next;
        node(int d){
            this->data = d;
            this->next = NULL;
            this->prev = NULL;
        }
};
node *START = NULL;
node *END = NULL;
node* createDLL(node* start){
    node *newNode, *ptr;
    ptr = start;
    int data = 1;
    while(data){
        cout<<"Enter data : ";
        cin>>data;
        newNode = new node(data);
        if(data == -1) break;
        if(start == NULL){
            start = newNode;
            END = newNode;
        }else{
            ptr = END;
            ptr->next = newNode;
            newNode->prev = ptr;
            END = newNode;
        }
    }
    return start;
}
node* insert_begi(node* start){
    node *ptr = start, *newNode;
    int data;
    cout<<"Enter data : ";
    cin>>data;
    newNode = new node(data);
    newNode->next = ptr;;
    ptr->prev = newNode;
    start = newNode;
    return start;
}
node* insert_end(node* start){
    node* newNode, *ptr;
    ptr = END;
    int data;
    cout<<"Enter data : ";
    cin>>data;
    newNode = new node(data);
    ptr->next = newNode;
    newNode->prev = ptr;
    END = newNode;
    return start;
}
node* delete_begi(node* start){
    node* ptr = start;
    start = ptr->next;
    delete(ptr);
    return start;
}
node* delete_end(node* start){
    node* ptr = END;
    END = ptr->prev;
    END->next = NULL;
    delete(ptr);
    return start;

}
node* insert_at(node* start){
    int position, data, i = 1;
    node *newNode, *ptr;
    cout<<"Enter position : ";
    cin>>position;
    if(position == 1){
        start = insert_begi(start);
    }else{   
        cout<<"Enter data : ";
        cin>>data;
        ptr = start;
        while(i < position-1){
            i++;
            ptr = ptr->next;
        }
        newNode = new node(data);
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next->prev = newNode;
        ptr->next = newNode;
        END = newNode;
        return start;
    }
}
node* delete_at(node* start){
    node* ptr = start;
    int posi;
    cout<<"Enter the position to delete : ";
    cin>>posi;
    int i = 1;
    if(posi == 1){
        start = delete_begi(start);
    }else{
        while(i <= posi - 1){
            i++;
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete(ptr);
    }
    return start;
}
node* display(node* start){
    node *ptr = start;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }return start;
}
int main(){
    START = createDLL(START);
    cout<<"Doubly Linked List : ";
    START = display(START);
    /*cout<<"Inserting 9 at beginning : ";
    START = insert_begi(START);
    START = display(START);*/
    /*cout<<"\nInserting at a  position : ";
    START = insert_at(START);
    START = display(START);*/
    /*cout<<"\nDelete from front : ";
    START = delete_begi(START);
    START = display(START);*/
    /*cout<<"\nInserting at last : ";
    START = insert_end(START);
    START = display(START);*/
    /*cout<<"\nDelete from END : ";
    START = delete_end(START);
    START = display(START);*/
    cout<<"\nDeleting at : ";
    START = delete_at(START);
    START = display(START);
    return 0;
}