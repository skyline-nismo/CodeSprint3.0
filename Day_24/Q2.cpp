#include <bits/stdc++.h>
using namespace std;

/* class Node{
    public:
    long long data;
    Node *next;

    Node(long long value) : data(value), next(nullptr){}
    
} */

struct Node{
    long long data;
    Node *next;
    
    Node(long long value){
        data = value;
        next = nullptr;
    }
    // Node(long long value) : data(value), next(nullptr){}
};

Node *createLinkedList(const vector<long long> &values, int n){
    Node *head = new Node(values[0]);
    Node *tail = head;
    for(int i = 1; i < n; i++){
        tail -> next = new Node(values[i]);
        tail = tail -> next;
    }
    return head;
}

long long findMiddleNodeValue(Node *head){
    Node *first = head;
    Node *second = head;
    while(first != nullptr && first -> next != nullptr){
        first = first -> next -> next;
        second = second -> next;
    }
    return second -> data;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000)
        return 0;
    vector<long long> values(n);
    for(int i = 0; i < n; i++){
        cin >> values[i];
        if(values[i] < -1000000000LL || values[i] > 1000000000LL)
            return 0;
    }
    Node *head = createLinkedList(values, n);
    cout << findMiddleNodeValue(head);
    return 0;
}