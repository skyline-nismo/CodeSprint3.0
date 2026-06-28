#include <bits/stdc++.h>
using namespace std;

long long findEvenLevelTreasure(int n, 
                                const vector<vector<int>> &adj, 
                                const vector<long long> &treasure){ 
    long long totalTreasure = 0;

    vector<bool> visited(n + 1, false);

    stack<pair<int, int>> st;
    st.push({1, 0}); // {node, level}

    while(!st.empty()){
        int node = st.top().first;
        int level = st.top().second;
        st.pop();

        if(visited[node])
            continue;

        visited[node] = true;

        if(level % 2 == 0)
            totalTreasure += treasure[node];

        for(int child : adj[node]){
            if(!visited[child])
                st.push({child, level + 1});
        }
    }

    return totalTreasure;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    if(n < 1 || n > 200000) return 0;

    vector<long long> treasure(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> treasure[i];
        if(treasure[i] < 1LL || treasure[i] > 1000000000LL) return 0;
    }

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;

        if(u < 1 || u > n || v < 1 || v > n) return 0;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << findEvenLevelTreasure(n, adj, treasure);

    return 0;
}