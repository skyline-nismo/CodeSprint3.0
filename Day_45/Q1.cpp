#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void initializeDistance(vector<vector<long long>> &dist, int n){
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
}

void floydWarshall(vector<vector<long long>> &dist, int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            if(dist[i][k] == INF)
                continue;

            for(int j = 1; j <= n; j++){
                if(dist[k][j] == INF)
                    continue;

                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void answerQueries(vector<vector<long long>> &dist, int q){
    while(q--){
        int a, b;
        cin >> a >> b;

        if(a < 1 || a >= dist.size() || b < 1 || b >= dist.size()) return;

        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Constraint checking
    if (n < 1 || n > 200 || m < 0 || m > n * n) return 0;

    vector<vector<long long>> dist(n + 1, vector<long long> (n + 1, INF));

    initializeDistance(dist, n);

    for(int i = 0; i < m; i++){
        int u, v;
        long long w;

        cin >> u >> v >> w;

        // if(u < 1 || u > n || v < 1 || v > n) return 0;

        if(w < 1 || w > 1000000) return 0;

        dist[u][v] = min(dist[u][v], w);
    }

    floydWarshall(dist, n);

    int q;
    cin >> q;

    if(q < 1 || q > 100000) return 0;

    answerQueries(dist, q);

    return 0;
}