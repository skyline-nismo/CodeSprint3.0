#include <bits/stdc++.h>
using namespace std;

/* class Node{
    public:
    long long data;
    Node *next;
    Node *random;

    Node(long long val){
        data = val;
        next = nullptr;
        random = nullptr;
    }
} */

struct Node{
    long long data;
    Node *next;
    Node *random;

    Node(long long value){
        data = value;
        next = nullptr;
        random = nullptr;
    }
};

Node *createLinkedList(const vector<long long> &userIDs, vector<Node*> &nodes){
    Node *head = new Node(userIDs[0]);
    nodes.push_back(head);
    Node *current = head;
    for(int i = 1; i < (int)userIDs.size(); i++){
        Node *newNode = new Node(userIDs[i]);
        current -> next = newNode;
        current = newNode;
        nodes.push_back(newNode);
    }
    return head;
}

void setRandomPointers(vector<Node*> &nodes, const vector<int> &randomIndex){
    for(int i = 0; i < (int)nodes.size(); i++){
        if(randomIndex[i] != -1)
            nodes[i] -> random = nodes[randomIndex[i]];
    }
}

Node *cloneLinkedList(Node *head){
    if(head == nullptr)
        return nullptr;
    unordered_map<Node*, Node*> mp;
    Node *temp = head;
    while(temp != nullptr){
        mp[temp] = new Node(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp != nullptr){
        mp[temp] -> next = (temp -> next != nullptr) ? mp[temp -> next] : nullptr;
        mp[temp] -> random = (temp -> random != nullptr) ? mp[temp -> random] : nullptr;
        temp = temp -> next;
    }
    return mp[head];
}

void printClonedLinkedList(Node *clonedHead){
    vector<Node*> clonedNodes;
    Node *temp = clonedHead;
    while(temp != nullptr){
        clonedNodes.push_back(temp);
        temp = temp -> next;
    }
    unordered_map<Node*, int> indexMap;
    for(int i = 0; i < (int)clonedNodes.size(); i++){
        indexMap[clonedNodes[i]] = i;
    }
    for(int i = 0; i < (int)clonedNodes.size(); i++){
        cout << clonedNodes[i] -> data << " ";
        cout << (clonedNodes[i] -> random == nullptr ? -1 : indexMap[clonedNodes[i] -> random]);
        cout << "\n";
    }
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000)
        return 0;
    vector<long long> userIDs(n);
    for(int i = 0; i < n; i++){
        cin >> userIDs[i];
        if(userIDs[i] < 1LL || userIDs[i] > 1000000000LL)
            return 0;
    }
    vector<int> randomIndex(n);
    for(int i = 0; i < n; i++){
        cin >> randomIndex[i];
        if(randomIndex[i] < -1 || randomIndex[i] >= n)
            return 0;
    }
    vector<Node*> originalNodes;
    Node *head = createLinkedList(userIDs, originalNodes);
    setRandomPointers(originalNodes, randomIndex);
    Node *clonedHead = cloneLinkedList(head);
    printClonedLinkedList(clonedHead);
    return 0;
}