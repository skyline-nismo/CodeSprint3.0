#include <bits/stdc++.h>
using namespace std;

bool isValidExpression(const string &s){
    if(s.length() < 1 || s.length() > 100000) return false;
    for(char ch : s){
        if(!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            return false;
        }
    }
    return true;
}

long long evaluateExpression(const string &s){
    stack<long long> st;
    long long num = 0;
    char op = '+';
    for(int i = 0; i <= (int)s.length(); i++){
        if(i < (int)s.length() && isdigit(s[i])){
            num = num * 10 + (s[i] - '0');
        }else{
            if(op == '+'){
                st.push(num);
            }else if(op == '-'){
                st.push(-num);
            }else if(op == '*'){
                long long top = st.top();
                st.pop();
                st.push(top * num);
            }else if(op == '/'){
                long long top = st.top();
                st.pop();
                st.push(top / num);
            }
            if(i < (int)s.length())
                op = s[i];
            num = 0;
        }
    }

    long long answer = 0;
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    return answer;
}

int main(){
    string s;
    cin >> s;
    if(!isValidExpression(s)) return 0;
    cout << evaluateExpression(s);
    return 0;
}