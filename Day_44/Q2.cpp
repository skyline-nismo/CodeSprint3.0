#include <bits/stdc++.h>
using namespace std;

bool dfs(int current, int visitedCount, 
        const vector<vector<int>> &graph,
        vector<bool> &visited, 
        int n){

    if(visitedCount == n) return true;

    for(int next : graph[current]){
        if(!visited[next]){
            visited[next] = true;

            if(dfs(next, visitedCount + 1, graph, visited, n))
                return true;

            visited[next] = false;
        }
    }

    return false;
}

bool isMissionPossible(const vector<vector<int>> &graph, int n){

    for(int start = 1; start <= n; start++){

        vector<bool> visited(n + 1, false);

        visited[start] = true;

        if(dfs(start, 1, graph, visited, n))
            return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    if(n < 2 || n > 18 || m < 1 || m > n * (n - 1) / 2) return 0;

    vector<vector<int>> graph(n + 1);

    for(int i = 0; i < m; i++){

        int u, v;
        cin >> u >> v;

        if(u < 1 || u > n || v < 1 || v > n) return 0;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << (isMissionPossible(graph, n) ? "MISSION POSSIBLE" : "MISSION FAILED");

    return 0;
}