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

Node *createLinkedList(vector<long long> &arr, int n){
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i < n; i++){
        temp -> next = new Node(arr[i]);
        temp = temp -> next;
    }
    return head;
}

Node *findNode(Node *head, long long x){
    while(head != NULL){
        if(head -> data == x){
            return head;
        }
        head = head -> next;
    }
    return NULL;
}

Node *createSecondLinkedList(vector<long long> &arr, Node *intersect, int n){
    Node *head = NULL;
    Node *temp = NULL;
    int i = 0;
    while(i < n){
        if(intersect != NULL && arr[i] == intersect -> data){
            /*if(temp != NULL){
                temp -> next = intersect;
            }else{
                head = intersect;
            }*/
            temp != NULL ? temp -> next = intersect : head = intersect;
            break;
        }
        Node *newNode = new Node(arr[i]);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp -> next = newNode;
            temp = newNode;
        }
        i++;
    }
    return head;
}

Node *getIntersection(Node *first, Node *second){
    Node* p1 = first;
    Node* p2 = second;
    while(p1 != p2){
        p1 = (p1 == NULL) ? second : p1 -> next;
        p2 = (p2 == NULL) ? first : p2 -> next;
    }
    return p1;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000){
        return 0;
    }
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 1 || a[i] > 1000000000LL){
            return 0;
        }
    }
    int m;
    cin >> m;
    if (m < 1 || m > 100000){
        return 0;
    }
    vector<long long> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
        if(b[i] < 1 || b[i] > 1000000000LL){
            return 0;
        }
    }
    long long x;
    cin >> x;
    Node *first = createLinkedList(a, n);
    Node *intersect = NULL;
    if(x != -1){
        intersect = findNode(first, x);
    }
    Node *second = createSecondLinkedList(b, intersect, n);
    Node *ans = getIntersection(first, second);
    /*if(ans == NULL){
        cout << -1;-
    }else{
        cout << ans->data;
    }*/
    cout << (ans == NULL ? -1 : ans->data);
    return 0;
}