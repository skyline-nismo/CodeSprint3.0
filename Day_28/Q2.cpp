#include <bits/stdc++.h>
using namespace std;

void registerStudent(queue<long long> &q, long long studentId){
    q.push(studentId);
}

void withdrawStudent(queue<long long> &q){
    if(q.empty()){
        cout << -1 << "\n";
        return;
    }
    q.pop();
}

void callNextStudent(queue<long long> &q){
    if(q.empty()){
        cout << -1 << "\n";
        return;
    }
    cout << q.front() << "\n";
    q.pop();    
}

int main(){
    int q;
    cin >> q;
    if(q < 1 || q > 100000) return 0;
    queue<long long> interviewQueue;
    for(int i = 0; i < q; i++){
        string operation;
        cin >> operation;
        if(operation == "REGISTER"){
            long long x;
            cin >> x;
            if(x < 1LL || x > 1000000000LL) return 0;
            registerStudent(interviewQueue, x);
        }else if(operation == "WITHDRAW"){
            withdrawStudent(interviewQueue);
        }else if(operation == "NEXT"){
            callNextStudent(interviewQueue);
        }else{  
            return 0;
        }
    }
    return 0;
}