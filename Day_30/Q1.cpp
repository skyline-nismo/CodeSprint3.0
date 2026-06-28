#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch){
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int getPrecedence(char op){
    if(op == '*' || op == '/') return 2;

    if(op == '+' || op == '-') return 1;

    return 0;
}

string infixToPostfix(const string &s){
    stack<char> st;
    string postfix = "";

    for(char ch : s){
        if(isOperand(ch)){
            postfix += ch;
        }else if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();
        }else{
            while(!st.empty() && getPrecedence(st.top()) >= getPrecedence(ch)){
                if(st.top() == '(')
                    break;

                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main(){
    string s;
    cin >> s;
    if(s.length() < 1 || s.length() > 100000) return 0;
    cout << infixToPostfix(s);
    return 0;
}               