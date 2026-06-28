#include <bits/stdc++.h>
using namespace std;

bool isFull(int count, int capacity){
    return count == capacity;
}

bool isEmpty(int count){
    return count == 0;
}

void enqueueElement(vector<long long> &queueArray,
                    int capacity,
                    int &rear,
                    int &count,
                    long long value){
    if(isFull(count, capacity)){
        cout << "FULL\n";
        return;
    }

    rear = (rear + 1) % capacity;
    queueArray[rear] = value;
    count++;
}

void dequeueElement(int capacity,
                    int &front,
                    int &count){
    if(isEmpty(count)){
        cout << "EMPTY\n";
        return;
    }

    front = (front + 1) % capacity;
    count--;
}

void printFrontElement(const vector<long long> &queueArray,
                       int front,
                       int count){
    if(isEmpty(count)){
        cout << -1 << "\n";
        return;
    }

    cout << queueArray[front] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, q;
    cin >> k >> q;
    if(k < 1 || k > 100000 || q < 1 || q > 10000) return 0;

    vector<long long> queueArray(k);
    int front = 0;
    int rear = -1;
    int count = 0;
    for(int i = 0; i < q; i++){
        string operation;
        cin >> operation;
        
        if(operation == "ENQUEUE"){
            long long x;
            cin >> x;
            if(x < 1LL || x > 1000000000LL) return 0;

            enqueueElement(queueArray, k, rear, count, x);
        }else if(operation == "DEQUEUE"){
            dequeueElement(k, front, count);
        }else if(operation == "FRONT"){
            printFrontElement(queueArray, front, count);
        }else{
            return 0;
        }
    }

    return 0;
}