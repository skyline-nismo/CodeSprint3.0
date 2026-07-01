#include <bits/stdc++.h>
using namespace std;

/* class Edge{
    public:
    int to;
    long long travelTime;
    long long expiryTime;
}; */

struct Edge{
    int to;
    long long travelTime;
    long long expiryTime;
};

void dijkstra(int n, const vector<vector<Edge>> &graph){
    const long long INF = LLONG_MAX;

    vector<long long> dist(n + 1, INF);

    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        long long currentTime = pq.top().first;
        int currentCity = pq.top().second;
        pq.pop();

        if(currentTime > dist[currentCity])
            continue;

        for(Edge edge : graph[currentCity]){
            if(currentTime >= edge.expiryTime)
                continue;

            long long newTime = currentTime + edge.travelTime;

            if(newTime < dist[edge.to]){
                dist[edge.to] = newTime;
                pq.push({newTime, edge.to});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << (dist[i] == INF ? -1 : dist[i]);

        if(i != n)
            cout << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    if(n < 1 || n > 100000 || m < 1 || m > 200000) return 0;

    vector<vector<Edge>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        long long t, e;

        cin >> u >> v >> t >> e;

        if(u < 1 || u > n ||
            v < 1 || v > n ||
            t < 1LL || t > 1000000LL ||
            e < 1LL || e > 1000000000LL){
            return 0;
        }

        graph[u].push_back({v, t, e});
    }

    dijkstra(n, graph);

    return 0;
}