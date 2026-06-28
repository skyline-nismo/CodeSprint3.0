#include <bits/stdc++.h>
using namespace std;

bool isDigit(char ch){
    return (ch >= '0' && ch <= '9');
}

int applyOperation(int a, int b, char op){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    return a / b;
}

int evaluatePrefix(const string &s){
    stack<int> st;
    for(int i = s.size() - 1; i >= 0; i--){
        char ch = s[i];
        if(isDigit(ch)){
            st.push(ch - '0');
        }else{
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int result = applyOperation(op1, op2, ch);
            st.push(result);
        }
    }

    return st.top();
}

int main(){
    string s;
    cin >> s;
    if(s.length() < 1 || s.length() > 100000) return 0;
    cout << evaluatePrefix(s);
    return 0;
}