#include <bits/stdc++.h>
using namespace std;

bool isValidColor(const string &color){
    if(color.length() < 1 || color.length() > 20) 
        return false;

    for(const char ch : color){
        if(!isalpha(ch)) 
            return false;
    }

    return true;
}

bool checkConnected(unordered_map<string, vector<string>> &graph,
                    unordered_map<string, int> &inDegree,
                    unordered_map<string, int> &outDegree){

    unordered_set<string> visited;
    queue<string> q;

    string start = "";

    for(auto &it : outDegree){
        if(it.second + inDegree[it.first] > 0){
            start = it.first;
            break;
        }
    }

    if(start == "") return true;

    q.push(start);
    visited.insert(start);

    while(!q.empty()){
        string current = q.front();
        q.pop();

        for(string next : graph[current]){
            if(visited.find(next) == visited.end()){
                visited.insert(next);
                q.push(next);
            }
        }
    }

    unordered_set<string> vertices;

    for(auto &it : inDegree)
        vertices.insert(it.first);

    for(auto &it : outDegree)
        vertices.insert(it.first);

    for(string vertex : vertices){
        if(inDegree[vertex] + outDegree[vertex] > 0 &&
            visited.find(vertex) == visited.end())
            return false;
    }

    return true;
}

bool checkEulerPath(unordered_map<string, int> &inDegree,
                    unordered_map<string, int> &outDegree){

    unordered_set<string> vertices;

    for(auto &it : inDegree)
        vertices.insert(it.first);

    for(auto &it : outDegree)
        vertices.insert(it.first);

    int startNodes = 0;
    int endNodes = 0;

    for(string vertex : vertices){
        int in = inDegree[vertex];
        int out = outDegree[vertex];

        if(out - in == 1){
            startNodes++;
        }else if(in - out == 1){
            endNodes++;
        }else if(in != out){
            return false;
        }
    }

    if((startNodes == 1 && endNodes == 1) ||
        (startNodes == 0 && endNodes == 0))
        return true;

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    cin >> p;
    if(p < 1 || p > 200000) return 0;

    unordered_map<string, int> inDegree;
    unordered_map<string, int> outDegree;
    unordered_map<string, vector<string>> graph;

    for(int i = 0; i < p; i++){
        string startColor, endColor;
        cin >> startColor >> endColor;

        if(!isValidColor(startColor) || !isValidColor(endColor)) return 0;

        outDegree[startColor]++;
        inDegree[endColor]++;

        // Undirected graph for connectivity check
        graph[startColor].push_back(endColor);
        graph[endColor].push_back(startColor);
    }

    if(checkConnected(graph, inDegree, outDegree) &&
        checkEulerPath(inDegree, outDegree)){
        cout << "ASSEMBLY POSSIBLE";
    }else{
        cout << "ASSEMBLY IMPOSSIBLE";
    }

    return 0;
}