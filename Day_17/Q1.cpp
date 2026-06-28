#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long data;
    Node *next;

    Node(long long val){
        data = val;
        next = NULL;
    }
};

Node *createLinkedList(int n){
    long long x;
    cin >> x;
    if(x < -1000000000LL || x > 1000000000LL){
        return NULL;
    }
    Node *head = new Node(x);
    Node *tail = head;
    for(int i = 1; i < n; i++){
        cin >> x;
        if(x < -1000000000LL || x > 1000000000LL){
            return NULL;
        }
        tail -> next = new Node(x);
        tail = tail -> next;
    }
    return head;
}

Node *reverseLinkedList(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL){
        Node *nextNode = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void printLinkedList(Node *head){
    cout << endl;
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data;
        if(temp -> next != NULL){
            cout << " ";
        }
        temp = temp -> next;
    }
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000){
        return 0;
    }
    Node *head = createLinkedList(n);
    if(head == NULL){
        return 0;
    }
    head = reverseLinkedList(head);
    printLinkedList(head);
    return 0;
}