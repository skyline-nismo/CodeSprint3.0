#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m){
    return (row >= 0 && row < n && col >= 0 && col < m);
}

bool dfs(int row, int col, int index,
        const vector<vector<char>> &grid,
        vector<vector<bool>> &visited,
        string &word,
        int n, int m){
    if(index == word.length())
        return true;

    if(!isValid(row, col, n, m))
        return false;

    if(visited[row][col])
        return false;

    if(grid[row][col] != word[index])
        return false;

    visited[row][col] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for(int k = 0; k < 4; k++){
        int newRow = row + dr[k];
        int newCol = col + dc[k];

        if(dfs(newRow, newCol, index + 1, grid, visited, word, n, m))
            return true;
    }

    visited[row][col] = false;
    return false;
}

bool wordExists(const vector<vector<char>> &grid, string &word, int n, int m){
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == word[0]){
                if(dfs(i, j, 0, grid, visited, word, n, m))
                    return true;
            }
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Constraint check
    if(n < 1 || n > 6 || m < 1 || m > 6) return 0;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];

            if(grid[i][j] < 'A' || grid[i][j] > 'Z'){
                return 0;
            }
        }
    }

    string word;
    cin >> word;

    // Constraint check for word length
    if(word.length() < 1 || word.length() > 15) return 0;

    bool found = wordExists(grid, word, n, m);

    cout << (found ? "YES" : "NO");

    return 0;
}