#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

/* class Node{
public:
    int data;
    Node* npx;

    Node(int value) : data(value), npx(nullptr){}
}; */

struct Node{
    long long data;
    Node *npx;

    Node(long long value) : data(value), npx(nullptr){}
};

Node *XOR(Node *a, Node *b){
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

Node *insertEnd(Node *head, long long value){
    Node *newNode = new Node(value);
    if (head == nullptr)
        return newNode;
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while(true){
        next = XOR(prev, curr -> npx);
        if(next == nullptr)
            break;
        prev = curr;
        curr = next;
    }
    curr -> npx = XOR(prev, newNode);
    newNode -> npx = XOR(curr, nullptr);
    return head;
}

void traverse(Node *head){
    Node *curr = head;
    Node *prev = nullptr;
    Node *next;
    while(curr != nullptr){
        cout << curr -> data << " ";
        next = XOR(prev, curr -> npx);
        prev = curr;
        curr = next;
    }
}

int main(){
    /* ios::sync_with_stdio(false);
    cin.tie(nullptr); */

    int n;
    cin >> n;
    if(n < 1 || n > 100000)
        return 0;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 1LL || arr[i] > 1000000000LL)
            return 0;
    }
    Node *head = nullptr;
    for(int i = 0; i < n; i++)
        head = insertEnd(head, arr[i]);
    traverse(head);
    return 0;
}