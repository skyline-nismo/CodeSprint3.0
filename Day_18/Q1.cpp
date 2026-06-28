#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long data;
    Node *next;

    Node(long long value){
        data = value;
        next = NULL;
    }
};

Node *createLinkedList(vector<long long> &arr, int pos, int n){
    Node *head = new Node(arr[0]);
    Node *temp = head;
    Node *cycleNode = NULL;
    if (pos == 0){  
        cycleNode = head;
    }
    for(int i = 1; i < n; i++){
        Node *newNode = new Node(arr[i]);
        temp -> next = newNode;
        temp = newNode;
        if(i == pos){
            cycleNode = temp;
        }
    }
    if(pos != -1){
        temp -> next = cycleNode;
    }
    return head;
}

bool hasCycle(Node *head){
    Node *first = head;
    Node *second = head;
    while(first != NULL && first -> next != NULL){
        first = first -> next -> next;
        second = second -> next;
        if(first == second){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000){
        return 0;
    }
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < -1000000000LL || arr[i] > 1000000000LL){
            return 0;
        }
    }
    int POS;
    cin >> POS;
    if(POS < -1 || POS >= n){
        return 0;
    }
    Node *head = createLinkedList(arr, POS, n);
    if(hasCycle(head)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}