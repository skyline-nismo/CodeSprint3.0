#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n){
    // Check upper column
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'Q')
            return false;
    }

    // Check upper left diagonal
    int i = row - 1;
    int j = col - 1;

    while(i >= 0 && j >= 0){
        if(board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }

    // Check upper right diagonal
    i = row - 1;
    j = col + 1;

    while(i >= 0 && j < n){
        if(board[i][j] == 'Q')
            return false;
        i--;
        j++;
    }

    return true;
}

void solveNQueens(int row, int n, 
                vector<string> &board,
                vector<vector<string>> &solutions){
    if(row == n){
        solutions.push_back(board);
        return;
    }

    for(int col = 0; col < n; col++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';

            solveNQueens(row + 1, n, board, solutions);

            board[row][col] = '.';
        }
    }
}

void printSolutions(const vector<vector<string>> &solutions){
    if(solutions.empty()){
        cout << -1;
        return;
    }

    for(int i = 0; i < solutions.size(); i++){
        for(int j = 0; j < solutions[i].size(); j++){
            cout << solutions[i][j] << "\n";
        }

        if(i != solutions.size() - 1)
            cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    // Constraint check
    if(n < 1 || n > 9) return 0;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;

    solveNQueens(0, n, board, solutions);

    printSolutions(solutions);

    return 0;
}