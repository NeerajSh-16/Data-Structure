//Implementing a Simple Queue
#include <iostream>
using namespace std;
class CircularQueue{
    private:
        int *arr;
        int size;
        int front, rear;
    public:
        CircularQueue(int size);
        ~CircularQueue();
        void insert(int x);
        int delete_element();
        int peek(void);
        void display();
};
CircularQueue :: CircularQueue(int size){
    this->size = size;
    arr = new int[size];
    front = rear = -1;;
}
CircularQueue :: ~CircularQueue(){
    delete[] arr;
}
void CircularQueue :: insert(int x){
    if((rear + 1)% size == front){
        cout<<"Overflow\n";
        return;
    }
    if(front == -1 && rear == -1){
        front = rear = 0;
    }else if(rear == size - 1 && front != 0)
        rear = 0;
    else
        rear++;
    arr[rear] = x;
}
int CircularQueue :: delete_element(){
    int val;
    if(front == -1 && rear == -1){
        cout<<"Underflow\n";
        return -1;
    }
    if(front ==  rear){
        val = arr[front];
        front = rear = -1;
    }
    else{
        val = arr[front];
        if(front == size -1)
            front = 0;
        else
            front++;
    }
    return val;
}
int CircularQueue :: peek(){
    if(front == -1 || front > rear){
        cout<<"Queue is Empty\n";
        return -1;
    }else 
        return arr[front];
}
void CircularQueue :: display(){
    if(front == -1 || front > rear)
        cout<<"Queue is Empty\n";
    if(front < rear){
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<"|";
    }
    else{
        for(int i=front;i<size;i++)
            cout<<arr[i]<<"|";
        for(int i=0;i<=rear;i++)
            cout<<arr[i]<<"|";
    }
}
int main(){
    int size, choice;
    cout<<"Enter the size of your Queue : ";
    cin>>size;
    CircularQueue qu(size);
    cout<<"********MENU********\n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
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