#include<iostream>
using namespace std;
int convertFive(int n) {
    // Your code here
    string s = to_string(n);
    int noOfDigits = s.length();
    
    for(int i=0;i<s.length();i++){
        if(s[i] == '0'){
            s[i] = '5';
            cout<<"Done\n";
        }
    }
    cout<<s<<"\n";
    int nc = stoi(s);
    return nc;
}
int main(){
    int n;
    cin>>n;
    n = convertFive(n);
    cout<<n;
    return 0;
}