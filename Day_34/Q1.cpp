#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, int n, int m){
    return (row >= 0 && row < n && col >= 0 && col < m);
}

int findMinimumMinutes(vector<vector<int>> &grid, int n, int m){
    queue<pair<int, int>> q;
    int freshOranges = 0;

    // Store all rotten oranges and count fresh oranges
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
            }else if(grid[i][j] == 1){
                freshOranges++;
            }
        }
    }

    // No fresh oranges present
    if(freshOranges == 0) return 0;
    int minutes = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while(!q.empty()){
        int size = q.size();
        bool rottenSpread = false;

        for(int i = 0; i < size; i++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int newRow = row + dr[k];
                int newCol = col + dc[k];

                if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 2;
                    freshOranges--;
                    q.push({newRow, newCol});
                    rottenSpread = true;
                }
            }
        }

        if(rottenSpread)
            minutes++;
    }
    if(freshOranges > 0) return -1;

    return minutes;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // Constraint check
    if(n < 1 || n > 100 || m < 1 || m > 100) return 0;
    vector<vector<int>> grid(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    cout << findMinimumMinutes(grid, n, m);

    return 0;
}