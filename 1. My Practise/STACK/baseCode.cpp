//Implementing Stack
#include <iostream>
using namespace std;
class Stack{
    private:
        int size;
        int top;
        int *S;
    public:
        Stack(int size);
        ~Stack();
        void push(int x);
        int pop();
        int peek(int position);
        int isFull();
        int isEmpty();
        void display();
        int stackTop();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}
Stack::~Stack()
{
    delete[] S;
}
void Stack:: push(int x)
{
    if(isFull())
        cout<<"Stack Overflow"<<endl;
    else{
        top++;
        S[top] = x;
    }
}
int Stack::pop()
{
    int x = 1;
    if(isEmpty())
        cout<<"Stack Underflow"<<endl;
    else{
        x = S[top];
        top--;
    }
    return x;
}
int Stack::peek(int position)
{
    int x = -1;
    if(top-position+1 < 0 || top-position+1 == size)
        cout<<"Invalid Position !!!"<<endl;
    else{
        x = S[top-position+1];
    }
    return x;
}
int Stack::isFull()
{
    if(top == size-1)
        return 1; 
    return 0;
}
int Stack::isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}
void Stack::display()
{
    for(int i=top; i>=0; i--)
    {
        cout<<S[i]<<"|"<<flush;
    }
    cout<<endl;
}
int Stack::stackTop()
{
    if(isEmpty())
        return -1;
    return S[top];
}

int main()
{
    int Arr[] = {1,2,3,4,5,6};

    Stack stk(sizeof(Arr)/sizeof(Arr[0]));

    //Populate Stack with Array elements
    for(int i=0;i<sizeof(Arr)/sizeof(Arr[0]);i++)
    {
        stk.push(Arr[i]);
    }
    stk.push(11);

    cout<<"Stack Full "<<stk.isFull()<<endl;

    //Display Stack
    cout<<"Stack : "<<flush;
    stk.display();

    //Peek
    cout<<"Peek at 0th  : "<<stk.peek(0)<<endl;
    cout<<"Peek at 4th  : "<<stk.peek(4)<<endl;
    cout<<"Peek at 10th : "<<stk.peek(10)<<endl;

    //Top element
    cout<<"Stack Top : "<<stk.stackTop()<<endl;

    //Pop out elements
    for(int i=0;i<sizeof(Arr)/sizeof(Arr[0]);i++)
    {
        cout<<stk.pop()<<","<<flush;
    }
    cout<<endl;

    cout<<"Stack: "<<flush;
    stk.display();
    stk.pop();
    cout<<"Is Stack empty : "<<stk.isEmpty()<<endl;
}