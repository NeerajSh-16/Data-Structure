//Implementing a Simple Queue
#include <iostream>
using namespace std;
class Queue{
    private:
        int *arr;
        int size;
        int front, rear;
    public:
        Queue(int size);
        ~Queue();
        void insert(int x);
        int delete_element();
        int peek(void);
        void display();
};
Queue :: Queue(int size){
    this->size = size;
    arr = new int[size];
    front = rear = -1;;
}
Queue :: ~Queue(){
    delete[] arr;
}
void Queue :: insert(int x){
    if(rear == size - 1){
        cout<<"Overflow\n";
        return;
    }
    if(front == -1 && rear == -1){
        front = 0;
    }
    rear++;
    arr[rear] = x;
}
int Queue :: delete_element(){
    int val;
    if(front == -1 && rear == -1){
        cout<<"Underflow\n";
    }
    if(front ==  rear){
        val = arr[front];
        front = rear = -1;
    }
    else{
        val = arr[front];
        front++;
        return val;
    }
    return val;
}
int Queue :: peek(){
    if(front == -1 || front > rear){
        cout<<"Queue is Empty\n";
        return -1;
    }else 
        return arr[front];
}
void Queue :: display(){
    if(front == -1 || front > rear)
        cout<<"Queue is Empty\n";
    else{
        for(int i=0;i<=rear;i++)
            cout<<arr[i]<<"|";
    }
}
int main(){
    int size, choice;
    cout<<"Enter the size of your Queue : ";
    cin>>size;
    Queue qu(size);
    cout<<"********MENU********\n";
    cout<<"1. Insert from Rear\n";
    cout<<"2. Delete from Front\n";
    cout<<"3. Peek in the Queue\n";
    cout<<"4. Display Queue\n";
    do{
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice){
            case 1: int x;
                    cout<<"Enter the element to insert : ";
                    cin>>x;
                    qu.insert(x);
                    break;
            case 2: 
                    x = qu.delete_element();
                    cout<<x<<" is deleted from the queue\n";
                    break;
            case 3: 
                    x = qu.peek();
                    cout<<x<<" is at the top of the Queue\n";
                    break;
            case 4: cout<<"Queue : ";
                    qu.display();
                    break;
        }
    }while(choice != 5);
    return 0;
}