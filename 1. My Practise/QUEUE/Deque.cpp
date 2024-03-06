#include <iostream>
using namespace std;
class Deque{
    private:
        int *arr;
        int size;
        int front, rear;
    public:
        Deque(int size);
        ~Deque();
        void pushRear(int data);
        void pushFront(int data);
        int popFront();
        int popRear();
        void display();
};
Deque :: Deque(int size){
    this->size = size;
    arr = new int[size];
    front = rear = -1;
}
Deque :: ~Deque(){
    delete[] arr;
}
void Deque :: pushRear(int data){
    //Check for overflow
    //To insert 1st element
    //To insert element in a circular manner
    //----->rear n-1 par baitha h aur o wali position khali honi chahie
    //To inserting elements normally
    if((rear + 1)% size == front){
        cout<<"Deque Overflow\n";
        return;
    }
    if(front == -1)
        front = rear = 0;
    if(rear == size-1 && front != 0)
        rear = 0;
    else    
        rear++;
    arr[rear] = data;
}
void Deque :: pushFront(int data){

    //Check for overflow
    //To insert 1st element
    //To insert element in a circular manner
    //------>front zero par baitha h aur n-1 ki position khali honi chahie
    //To inserting elements normally
    if((rear + 1)% size == front){
        cout<<"Deque Overflow\n";
        return;
    }
    if(front == -1)
        front = rear = 0;
    if(front == 0 && rear != size-1)
        front = size-1;
    else    
        front--;
    arr[front] = data;
}
int Deque :: popFront(){
    //empty check
    //single element
    //circular flow
    //normal flow
    int x;
    if(front == -1){
        cout<<"Deque Underflow\n";
        return -1;
    }
    if(front == rear){
        x = arr[front];
        front = rear = -1;
    }
    if(front == size-1){
        x = arr[front];
        front = 0;
    }else{
        x = arr[front];
        front++;
    }
    return x;
}
int Deque :: popRear(){
    //empty check
    //single element
    //circular flow
    //normal flow
    int x;
    if(front == -1){
        cout<<"Deque Underflow\n";
        return -1;
    }
    if(front == rear){
        x = arr[front];
        front = rear = -1;
    }
    if(rear == 0){
        x = arr[rear];
        rear = size-1;
    }else{
        x = arr[rear];
        rear--;
    }
    return x;
}

void Deque :: display(){
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
    Deque qu(size);
    cout<<"********MENU********\n";
    cout<<"1. InsertFront\n";
    cout<<"2. InsertRear\n";
    cout<<"3. DeleteFront\n";
    cout<<"4. DeleteRear\n";
    cout<<"5. Display Queue\n";
    do{
        cout<<"\nEnter your choice : ";
        cin>>choice;
        int x;
        switch(choice){
            case 1:   cout<<"Enter the element to insert : ";
                    cin>>x;
                    qu.pushFront(x);
                    break;
            case 2: cout<<"Enter the element to insert : ";
                    cin>>x;
                    qu.pushRear(x);
                    break;
            case 3: x = qu.popFront();
                    cout<<x<<" is deleted from the queue\n";
                    break;
            case 4: x = qu.popRear();
                    cout<<x<<" is deleted from the queue\n";
                    break;
            case 5: cout<<"Queue : ";
                    qu.display();
                    break;
        }
    }while(choice != 6);
    return 0;
}
