#include <iostream>
using namespace std;
class TwoStack {
    private :
        int topA, topB;
        int size;
        int *arr;
    public :
        TwoStack(int size);
        ~TwoStack();
        void pushA(int x);
        void pushB(int x);
        int popA();
        int popB();
        int isAFull();
        int isBFull();
        int isAEmpty();
        int isBEmpty();
        void displayA();
        void displayB();
};
TwoStack :: TwoStack(int size){
    this->size = size;
    topA = -1;
    topB = size;
    arr = new int[size];
}
TwoStack :: ~TwoStack(){
    delete []arr;
}
void TwoStack :: pushA(int x){
    if(isAFull())
        cout<<"Stack A Overflow\n";
    else{
        topA++;
        arr[topA] = x;
    }
}
void TwoStack :: pushB(int x){
    if(isBFull())
        cout<<"Stack B Overflow\n";
    else{
        topB--;
        arr[topB] = x;
    }
}
int TwoStack :: popA(){
    int x;
    if(isAEmpty())
        cout<<"Stack A Underflow\n";
    else{
        x = arr[topA];
        topA--;
    }
    return x;
}
int TwoStack :: popB(){
    int x;
    if(isBEmpty())
        cout<<"Stack B Underflow";
    else{
        x = arr[topB];
        topB++;
    }
    return x;
}
int TwoStack :: isAEmpty(){
    if(topA == -1)
        return 1;
    return 0;
}
int TwoStack :: isBEmpty(){
    if(topB == size)
        return 1;
    return 0;
}
int TwoStack :: isAFull(){
    if(topA == topB - 1)
        return 1;
    return 0;
}
int TwoStack :: isBFull(){
    if(topB - 1 == topA)
        return 1;
    return 0;
}
void TwoStack :: displayA(){
    for(int i=topA;i>=0;i--)
        cout<<arr[i]<<"|"<<flush;
    cout<<endl;
}
void TwoStack :: displayB(){
    for(int i=topB;i<size;i++)
        cout<<arr[i]<<"|"<<flush;
    cout<<endl;
}
int main(){
    int size, option, x;;
    cout<<"Enter the size of your Complete Stack : ";
    cin>>size;
    TwoStack stk(size);
    do{
            cout<<"********MENU********\n";
            cout<<"1. Push in A\n";
            cout<<"2. Push in B\n";
            cout<<"3. Pop from A\n";
            cout<<"4. Pop from B\n";
            cout<<"5. Display Stack A\n";
            cout<<"6. Display Stack B\n\n";
            cout<<"Enter your choice : ";
            cin>>option;
            switch(option){
                case 1: cout<<"Enter the element to push in Stack A :  ";
                        cin>>x;
                        stk.pushA(x);
                        stk.displayA();
                        break;
                
                case 2: cout<<"Enter the element to push in Stack A :  ";
                        cin>>x;
                        stk.pushB(x);
                        stk.displayB();
                        break;
                case 3: stk.popA();
                        break;
                case 4: stk.popB();
                        break;
                case 5: stk.displayA();
                        break;
                case 6: stk.displayB();
                        break;
            }
    }while (option != 7);
    return 0;
    
}