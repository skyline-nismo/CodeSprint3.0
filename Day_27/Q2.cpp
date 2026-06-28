#include <bits/stdc++.h>
using namespace std;

bool searchTreasure(const vector<vector<long long>> &matrix,
                    int n, int m,
                    long long target){
    int low = 0;
    int high = n * m - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        long long value = matrix[row][col];
        if(value == target){
            return true;
        }else if(value < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n * m < 1 || n * m > 100000) return 0;
    vector<vector<long long>> matrix(n, vector<long long>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] < -1000000000LL || 
                matrix[i][j] > 1000000000LL) return 0;
        }
    }
    long long x;
    cin >> x;
    cout << (searchTreasure(matrix, n, m, x) ? "FOUND" : "NOT FOUND");
    return 0;
}