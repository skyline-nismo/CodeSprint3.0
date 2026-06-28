#include <bits/stdc++.h>
using namespace std;

/* class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
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

Node *buildTree(const vector<int> &arr){
    if(arr.empty() || arr[0] == -1)
        return nullptr;

    Node *root = new Node(arr[0]);

    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()){
        Node *current = q.front();
        q.pop();

        if(i < arr.size() && arr[i] != -1){
            current -> left = new Node(arr[i]);
            q.push(current -> left);
        }
        i++;

        if(i < arr.size() && arr[i] != -1){
            current -> right = new Node(arr[i]);
            q.push(current -> right);
        }
        i++;
    }

    return root;
}

bool isLeaf(const Node *node){
    if(node == nullptr) return false;

    return (node -> left == nullptr && node -> right == nullptr);
}

void addLeftBoundary(const Node *root, vector<int> &answer){
    const Node *curr = root -> left;

    while(curr != nullptr){
        if(!isLeaf(curr))
            answer.push_back(curr -> data);

        curr -> left != nullptr ? curr = curr -> left : curr = curr -> right;
    }
}

void addLeaves(const Node *root, vector<int> &answer){
    if(root == nullptr) return;

    if(isLeaf(root)){
        answer.push_back(root -> data);
        return;
    }

    addLeaves(root -> left, answer);
    addLeaves(root -> right, answer);
}

void addRightBoundary(const Node *root, vector<int> &answer){
    vector<int> temp;

    const Node *curr = root -> right;

    while(curr != nullptr){
        if(!isLeaf(curr))
            temp.push_back(curr -> data);

        curr -> right != nullptr ? curr = curr -> right : curr = curr -> left;
    }

    for(int i = temp.size() - 1; i >= 0; i--){
        answer.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(const Node *root){
    vector<int> answer;

    if(root == nullptr) return answer;

    /* if (!isLeaf(root)){
        answer.push_back(root -> data);
    }else{
        answer.push_back(root -> data);
        return answer;
    } */

    answer.push_back(root -> data);
    if (isLeaf(root))
        return answer;

    addLeftBoundary(root, answer);
    addLeaves(root, answer);
    addRightBoundary(root, answer);

    return answer;
}

void printAnswer(const vector<int> &answer){
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i];

        if(i != answer.size() - 1)
            cout << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    if(n < 1 || n > 10000) return 0;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(arr[i] != -1)
            if(arr[i] < 1 || arr[i] > 100000) return 0;
    }

    Node *root = buildTree(arr);

    vector<int> answer = boundaryTraversal(root);

    printAnswer(answer);

    return 0;
}