#include <bits/stdc++.h>
using namespace std;

bool isMatching(char openBracket, char closeBracket){
    if(openBracket == '(' && closeBracket == ')') return true;

    if(openBracket == '[' && closeBracket == ']') return true;

    if(openBracket == '{' && closeBracket == '}') return true;

    if(openBracket == '<' && closeBracket == '>') return true;

    return false;
}

bool isValidAttendanceLog(string s){
    stack<char> st;
    for(char ch : s){
        if(ch == '(' || ch == '[' || ch == '{' || ch == '<'){
            st.push(ch);
        }else{
            if(st.empty()) return false;

            if(!isMatching(st.top(), ch)) return false;

            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin >> s;
    if(s.length() < 1 || s.length() > 100000) return 0;
    for(char ch : s){
        if(ch != '(' && ch != ')' && 
            ch != '[' && ch != ']' &&
            ch != '{' && ch != '}' &&
            ch != '<' && ch != '>'){
            return 0;
        }
    }
    cout << (isValidAttendanceLog(s) ? "VALID" : "INVALID") << endl;
    return 0;
}       