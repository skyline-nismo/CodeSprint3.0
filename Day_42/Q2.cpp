#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> tin, tout;
vector<long long> value;
vector<long long> flatTree;
vector<long long> bit;

int timer = 0;

void dfs(int node, int parent){
    timer++;
    tin[node] = timer;
    flatTree[timer] = value[node];

    for(int child : graph[node]){
        if(child != parent){
            dfs(child, node);
        }
    }

    tout[node] = timer;
}

void updateBIT(int index, long long diff, int n){
    while(index <= n){
        bit[index] += diff;
        index += (index & -index);
    }
}

long long queryBIT(int index){
    long long sum = 0;

    while(index > 0){
        sum += bit[index];
        index -= (index & -index);
    }

    return sum;
}

void buildBIT(int n){
    for(int i = 1; i <= n; i++)
        updateBIT(i, flatTree[i], n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    // Constraint Check
    if(n < 1 || n > 200000 || q < 1 || q > 200000) return 0;

    graph.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    value.resize(n + 1);
    flatTree.resize(n + 1);
    bit.assign(n + 1, 0);

    for(int i = 1; i <= n; i++){
        cin >> value[i];

        if(value[i] < 1 || value[i] > 1000000000LL)
            return 0;
    }

    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;

        if(u < 1 || u > n || v < 1 || v > n) return 0;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);

    buildBIT(n);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int x;
            long long v;

            cin >> x >> v;

            if(x < 1 || x > n) return 0;

            if(v < 1LL || v > 1000000000LL) return 0;

            long long diff = v - value[x];
            value[x] = v;

            updateBIT(tin[x], diff, n);
        }else if(type == 2){
            int x;
            cin >> x;

            if(x < 1 || x > n) return 0;

            long long ans = queryBIT(tout[x]) - queryBIT(tin[x] - 1);

            cout << ans << "\n";
        }else{
            return 0;
        }
    }

    return 0;
}