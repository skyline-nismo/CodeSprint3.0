#include <bits/stdc++.h>
using namespace std;

/* class Node{
    long long data;
    Node *left;
    Node *right;

    Node(long long value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
} */

struct Node{
    long long data;
    Node *left;
    Node *right;

    Node(long long value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *buildTree(const vector<long long> &arr){
    if(arr.empty() || arr[0] == -1) return nullptr;

    Node *root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()){
        Node *curr = q.front();
        q.pop();

        if(i < arr.size() && arr[i] != -1){
            curr -> left = new Node(arr[i]);
            q.push(curr -> left);
        }
        i++;

        if(i < arr.size() && arr[i] != -1){
            curr -> right = new Node(arr[i]);
            q.push(curr -> right);
        }
        i++;
    }

    return root;
}

void recoverBST(Node *root){
    Node *first = nullptr;
    Node *second = nullptr;
    Node *prev = nullptr;
    Node *curr = root;

    while(curr != nullptr){
        if(curr -> left == nullptr){
            if(prev != nullptr && prev -> data > curr -> data){
                if(first == nullptr){
                    first = prev;
                    second = curr;
                }else{
                    second = curr;
                }
            }

            prev = curr;
            curr = curr -> right;
        }else{
            Node *predecessor = curr -> left;

            while(predecessor -> right != nullptr && predecessor -> right != curr){
                predecessor = predecessor -> right;
            }

            if(predecessor -> right == nullptr){
                predecessor -> right = curr;
                curr = curr -> left;
            }else{
                predecessor -> right = nullptr;

                if(prev != nullptr && prev -> data > curr -> data){
                    if(first == nullptr){
                        first = prev;
                        second = curr;
                    }else{
                        second = curr;
                    }
                }

                prev = curr;
                curr = curr -> right;
            }
        }
    }

    if(first != nullptr && second != nullptr)
        swap(first -> data, second -> data);
}

/* void printLevelOrder(const Node *root){
    if(root == nullptr)
        return;

    queue<const Node*> q;
    q.push(root);

    while(!q.empty()){
        const Node *curr = q.front();
        q.pop();

        if(curr == nullptr){
            cout << -1 << " ";
        }else{
            cout << curr -> data << " ";
            q.push(curr -> left);
            q.push(curr -> right);
        }
    }
} */

/* void printLevelOrder(const Node *root){
    if(root == nullptr) return;

    vector<long long> ans;
    queue<const Node*> q;
    q.push(root);

    while(!q.empty()){
        const Node *curr = q.front();
        q.pop();

        if(curr){
            ans.push_back(curr -> data);
            q.push(curr -> left);
            q.push(curr -> right);
        }else{
            ans.push_back(-1);
        }
    }

    while(!ans.empty() && ans.back() == -1)
        ans.pop_back();

    for(const long long x : ans)
        cout << x << " ";
} */

void printLevelOrder(const Node *root){
    if(!root) return;

    queue<const Node*> q;
    q.push(root);

    while(!q.empty()){
        const int sz = q.size();
        bool hasNextLevel = false;

        for(int i = 0; i < sz; i++){
            const Node *curr = q.front();
            q.pop();

            if(curr){
                cout << curr -> data << " ";
                q.push(curr -> left);
                q.push(curr -> right);

                if(curr -> left || curr -> right)
                    hasNextLevel = true;
            }else{
                cout << -1 << " ";
            }
        }

        if(!hasNextLevel)
            break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Constraint check
    if(n < 2 || n > 10000) return 0;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(arr[i] != -1)
            if(arr[i] < -1000000000LL || arr[i] > 1000000000LL) return 0;
    }

    Node *root = buildTree(arr);

    recoverBST(root);

    printLevelOrder(root);

    return 0;
}