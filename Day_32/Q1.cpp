#include <bits/stdc++.h>
using namespace std;

void registerToken(stack<long long> &inputStack, long long token){
    inputStack.push(token);
}

void transferElements(stack<long long> &inputStack,
                      stack<long long> &outputStack){
    while(!inputStack.empty()){
        outputStack.push(inputStack.top());
        inputStack.pop();
    }
}

void processNext(stack<long long> &inputStack,
                 stack<long long> &outputStack){
    if(outputStack.empty()){
        transferElements(inputStack, outputStack);
    }

    if(outputStack.empty()){
        cout << -1 << "\n";
        return;
    }

    cout << outputStack.top() << "\n";
    outputStack.pop();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    if(q < 1 || q > 100000) return 0;

    stack<long long> inputStack;
    stack<long long> outputStack;

    for(int i = 0; i < q; i++){
        string operation;
        cin >> operation;

        if(operation == "REGISTER"){
            long long token;
            cin >> token;
            if(token < 1LL || token > 1000000000LL) return 0;

            registerToken(inputStack, token);
        }else if(operation == "NEXT"){
            processNext(inputStack, outputStack);
        }else{
            return 0;
        }
    }

    return 0;
}