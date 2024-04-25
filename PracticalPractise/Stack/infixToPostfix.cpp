#include <iostream>
#include <stack>
using namespace std;
int prec(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    return 0;
}
string infixToPostfix(string s){
    stack<char> stk;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            res += s[i];
        }else if(s[i] == '('){
            stk.push(s[i]);
        }else if(s[i] == ')'){
            while(!stk.empty() && stk.top() != '('){
                res += stk.top();
                stk.pop();
            }if(!stk.empty()){
                stk.pop();
            }
        }else{
            while(!stk.empty() && prec(stk.top())>prec(s[i])){
                res += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}
int main(){
    string res = infixToPostfix("(a-b/c)*(a/k-l)");
    cout<<res;
}