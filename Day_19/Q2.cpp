#include <bits/stdc++.h>
using namespace std;

/* class Node{
public:
    long long data;
    Node *next;
    Node *prev;

    Node(long long value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
}; */

struct Node{
    long long data;
    Node *next;
    Node *prev;

    Node(long long value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

bool isValidInput(int n, long long k){
    if (n < 1 || n > 100000)
        return false;
    if (k < 0LL || k > 1000000000LL)
        return false;
    return true;
}

Node *createLinkedList(const vector<long long> &arr, Node *&tail, int n){
    Node *head = new Node(arr[0]);
    tail = head;
    for(int i = 1; i < n; i++){
        /* Node *temp = new Node(arr[i]);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp; */
        tail -> next = new Node(arr[i]);
        tail -> next -> prev = tail;
        tail = tail -> next;
    }
    return head;
}

Node *rotateRight(Node *head, long long k, int n){
    if (head == nullptr || head -> next == nullptr || k == 0)
        return head;
    k %= n;
    if (k == 0)
        return head;
    Node *tail = head;
    while(tail -> next != nullptr)
        tail = tail -> next;
    tail -> next = head;
    head -> prev = tail;
    long long stepsToNewTail = n - k;
    Node *newTail = head;
    for(int i = 1; i < stepsToNewTail; i++)
        newTail = newTail -> next;
    Node *newHead = newTail -> next;
    newTail -> next = nullptr;
    newHead -> prev = nullptr;
    return newHead;
}

void printLinkedList(Node *head){
    Node *temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main(){
    int n;
    long long k;
    cin >> n >> k;
    if(!isValidInput(n, k))
        return 0;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] < -1000000000LL || arr[i] > 1000000000LL)
            return 0;
    }
    Node *tail = nullptr;
    Node *head = createLinkedList(arr, tail, n);
    head = rotateRight(head, k, n);
    printLinkedList(head);
    return 0;
}