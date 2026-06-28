#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, 
            vector<vector<int>> &maze,
            vector<vector<int>> &visited){
    return (x >= 0 && x < n &&
            y >= 0 && y < n &&
            maze[x][y] == 1 &&
            visited[x][y] == 0);
}

void findPaths(int x, int y, int n,
               vector<vector<int>> &maze,
               vector<vector<int>> &visited,
               string path,
               vector<string> &ans){
    // Destination reached
    if(x == n - 1 && y == n - 1){
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // Down
    if(isSafe(x + 1, y, n, maze, visited)){
        findPaths(x + 1, y, n, maze, visited, path + 'D', ans);
    }
    // Left
    if(isSafe(x, y - 1, n, maze, visited)){
        findPaths(x, y - 1, n, maze, visited, path + 'L', ans);
    }
    // Right
    if(isSafe(x, y + 1, n, maze, visited)){
        findPaths(x, y + 1, n, maze, visited, path + 'R', ans);
    }
    // Up
    if(isSafe(x - 1, y, n, maze, visited)){
        findPaths(x - 1, y, n, maze, visited, path + 'U', ans);
    }
    // Backtracking
    visited[x][y] = 0;
}

int main(){
    int n;
    cin >> n;
    if (n < 1 || n > 8)
        return 0;
    vector<vector<int>> maze(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
            if(maze[i][j] != 0 && maze[i][j] != 1)
                return 0;
        }
    }
    vector<string> ans;
    // If start or destination is blocked
    if(maze[0][0] == 0 || maze[n - 1][n - 1] == 0){
        cout << -1;
        return 0;
    }
    vector<vector<int>> visited(n, vector<int> (n, 0));
    findPaths(0, 0, n, maze, visited, "", ans);
    if(ans.empty()){
        cout << -1;
    }else{
        for(string path : ans)
            cout << path << endl;
    }
    return 0;
}