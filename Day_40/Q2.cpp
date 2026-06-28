#include <bits/stdc++.h>
using namespace std;

/* class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
} */

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *insertNode(Node *root, int value){
    if(root == NULL)
        return new Node(value);

    Node *current = root;

    while (true){
        if(value < current -> data){
            if(current -> left == nullptr){
                current -> left = new Node(value);
                break;
            }
            current = current -> left;
        }else{
            if(current -> right == nullptr){
                current -> right = new Node(value);
                break;
            }
            current = current -> right;
        }
    }

    return root;
}

int findKthLargest(Node *root, int k){
    stack<Node*> st;
    Node *current = root;
    int count = 0;

    while(current != nullptr || !st.empty()){
        while(current != nullptr){
            st.push(current);
            current = current -> right;
        }

        current = st.top();
        st.pop();

        count++;

        if(count == k)
            return current -> data;

        current = current -> left;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n < 1 || n > 100000) return 0;

    Node *root = nullptr;

    vector<int> scores(n);

    unordered_set<int> uniqueValues;

    for(int i = 0; i < n; i++){
        cin >> scores[i];

        if(scores[i] < -1000000000 || scores[i] > 1000000000) return 0;

        if(uniqueValues.count(scores[i])) return 0;

        uniqueValues.insert(scores[i]);
    }

    int k;
    cin >> k;
    if(k < 1 || k > n) return 0;

    for(int i = 0; i < n; i++){
        root = insertNode(root, scores[i]);
    }

    cout << findKthLargest(root, k);

    return 0;
}