#include <bits/stdc++.h>
using namespace std;

/* class Node{
public:
    int id;
    Node *next;

    Node(int value){
        id = value;
        next = nullptr;
    }
}; */

struct Node{
    int id;
    Node *next;

    Node(int value){
        id = value;
        next = nullptr;
    }
};

bool isValidInput(int num){
    if(num < 1 || num > 100000)
        return false;
    return true;
}

Node *createCircularLinkedList(const vector<int> &ids, int n){
    Node *head = new Node(ids[0]);
    Node *tail = head;
    for(int i = 1; i < n; i++){
        tail -> next = new Node(ids[i]);
        tail = tail -> next;
    }
    tail -> next = head;
    return head;
}

int findSurvivor(Node *head, int n, int k){
    Node *current = head;
    Node *previous = head;
    while(previous -> next != head)
        previous = previous -> next;
    while(n > 1){
        for(int count = 1; count < k; count++){
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        Node *nodeToDelete = current;
        current = current -> next;
        delete nodeToDelete;
        n--;
    }
    return current -> id;
}

int main(){
    int n;
    cin >> n;
    if(!isValidInput(n))
        return 0;
    vector<int> ids(n);
    for(int i = 0; i < n; i++){
        cin >> ids[i];
    }
    int k;
    cin >> k;
    if(!isValidInput(k))
        return 0;
    Node *head = createCircularLinkedList(ids, n);
    cout << findSurvivor(head, n, k);
    return 0;
}