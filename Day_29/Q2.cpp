#include <bits/stdc++.h>
using namespace std;

bool isValidString(const string &s){
    if(s.length() < 1 || s.length() > 100000) return false;

    for(char ch : s)
        if(ch < 'a' || ch > 'z') return false;

    return true;
}

string cleanCaption(const string &s){
    stack<char> st;
    for(char ch : s)
        (!st.empty() && st.top() == ch) ? st.pop() : st.push(ch);

    string result = "";

    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
}

int main(){
    string s;
    cin >> s;
    if(!isValidString(s)) return 0;
    string answer = cleanCaption(s);
    cout << (answer.empty() ? "EMPTY" : answer);
    // cout << (cleanCaption(s).empty() ? "EMPTY" : cleanCaption(s));
    return 0;
}