#include <bits/stdc++.h>
using namespace std;

/* class Edge{
    public:
    int from;
    int to;
    long long weight;
}; */

struct Edge{
    int from;
    int to;
    long long weight;
};

const long long NEG_INF = -(1LL << 60);

void dfs(int node, const vector<vector<int>> &reverseGraph, vector<bool> &visited){
    visited[node] = true;

    for(int next : reverseGraph[node]){
        if(!visited[next])
            dfs(next, reverseGraph, visited);
    }
}

void findMaximumProfit(int n, const vector<Edge> &edges, const vector<vector<int>> &reverseGraph){
    vector<long long> profit(n + 1, NEG_INF);
    profit[1] = 0;

    // Bellman-Ford for maximum profit
    for(int i = 1; i <= n - 1; i++){
        bool updated = false;

        for(Edge edge : edges){
            if(profit[edge.from] == NEG_INF)
                continue;

            if(profit[edge.from] + edge.weight > profit[edge.to]){
                profit[edge.to] = profit[edge.from] + edge.weight;
                updated = true;
            }
        }

        if(!updated)
            break;
    }

    // Find all nodes that can reach destination
    vector<bool> canReachDestination(n + 1, false);
    dfs(n, reverseGraph, canReachDestination);

    // Check for profitable cycle affecting destination
    for(Edge edge : edges){
        if(profit[edge.from] == NEG_INF)
            continue;

        if(profit[edge.from] + edge.weight > profit[edge.to] &&
            canReachDestination[edge.to]){
            cout << "INFINITE PROFIT";
            return;
        }
    }

    cout << (profit[n] == NEG_INF ? "UNREACHABLE" : to_string(profit[n]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    if(n < 2 || n > 2500 || m < 1 || m > 5000) return 0;

    vector<Edge> edges;
    vector<vector<int>> reverseGraph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        long long w;

        cin >> u >> v >> w;

        if(u < 1 || u > n ||
            v < 1 || v > n ||
            w < -1000000000LL || w > 1000000000LL){
            return 0;
        }

        edges.push_back({u, v, w});
        reverseGraph[v].push_back(u);
    }

    findMaximumProfit(n, edges, reverseGraph);

    return 0;
}