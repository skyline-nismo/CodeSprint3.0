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

Node *removeKthFromEnd(Node *head, int k){
    Node *dummy = new Node(0);
    dummy -> next = head;
    Node *first = dummy;
    Node *second = dummy;   
    for (int i = 0; i < k; i++){
        first = first -> next;
    }
    while(first -> next != NULL){
        first = first -> next;
        second = second -> next;
    }

    Node *nodeToDelete = second -> next;
    second -> next = second -> next -> next;
    delete nodeToDelete;
    Node *newHead = dummy -> next;
    delete dummy;
    return newHead;
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
    int k;
    cin >> k;
    if(k < 1 || k > n){
        return 0;
    }
    head = removeKthFromEnd(head, k);
    printLinkedList(head);
    return 0;
}