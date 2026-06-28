#include <bits/stdc++.h>
using namespace std;

void pushElement(stack<long long> &mainStack,
                 stack<long long> &minStack,
                 long long value){
    mainStack.push(value);
    if(minStack.empty() || value <= minStack.top())
        minStack.push(value);
}

void popElement(stack<long long> &mainStack,
                stack<long long> &minStack){
    if(mainStack.empty()) return;

    if(mainStack.top() == minStack.top()) minStack.pop();

    mainStack.pop();
}

void printMinimum(const stack<long long> &minStack){
    if(minStack.empty()){
        cout << -1 << '\n';
    }else{
        cout << minStack.top() << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    if(q < 1 || q > 100000) return 0;

    stack<long long> mainStack;
    stack<long long> minStack;
    for(int i = 0; i < q; i++){
        string operation;
        cin >> operation;

        if(operation == "PUSH"){
            long long x;
            cin >> x;

            if(x < 0LL || x > 1000000000LL) return 0;
            pushElement(mainStack, minStack, x);
        }else if(operation == "POP"){
            popElement(mainStack, minStack);
        }else if(operation == "MIN"){
            printMinimum(minStack);
        }else{
            return 0;
        }
    }

    return 0;
}