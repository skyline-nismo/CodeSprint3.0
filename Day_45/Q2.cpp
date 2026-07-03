#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, const vector<vector<int>> &graph, vector<int> &color){
    queue<int> q;

    q.push(start);
    color[start] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int neighbour : graph[node]){
            if(color[neighbour] == 0){
                color[neighbour] = (color[node] == 1) ? 2 : 1;
                q.push(neighbour);
            }else if(color[neighbour] == color[node]){
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(const vector<vector<int>> &graph, 
                    vector<int> &color, 
                    int n){
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if(!bfs(i, graph, color)) return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Constraint checking
    if(n < 1 || n > 100000 || m < 0 || m > 200000) return 0;

    vector<vector<int>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        // if(u < 1 || u > n || v < 1 || v > n) return 0;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(n + 1, 0);

    if(!isBipartite(graph, color, n)){
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }

    return 0;
}