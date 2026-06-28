#include <bits/stdc++.h>
using namespace std;

void addRequest(stack<int> &s1, int floor){
    s1.push(floor);
}

void transferElements(stack<int> &s1, stack<int> &s2){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
}

void serveNextRequest(stack<int> &s1, stack<int> &s2){
    if(s2.empty()){
        transferElements(s1, s2);
    }

    if(s2.empty()){
        cout << -1 << '\n';
    }else{
        cout << s2.top() << '\n';
        s2.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    if(q < 1 || q > 100000) return 0;
    stack<int> s1, s2;
    for(int i = 0; i < q; i++){
        string operation;
        cin >> operation;
        if(operation == "ADD"){
            int floor;
            cin >> floor;
            if(floor < 0 || floor > 100000) return 0;
            addRequest(s1, floor);
        }else if(operation == "NEXT"){
            serveNextRequest(s1, s2);
        }else{
            return 0;
        }
    }
    return 0;
}