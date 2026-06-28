#include <bits/stdc++.h>
using namespace std;

void readMatrix(vector<vector<int>> &matrix, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];

            if(matrix[i][j] < 1 || matrix[i][j] > 100000){
                exit(0);
            }
        }
    }
}

vector<int> diagonalTraversal(const vector<vector<int>> &matrix, 
                                int m, int n){
    vector<vector<int>> diagonals(m + n - 1);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            diagonals[i + j].push_back(matrix[i][j]);
        }
    }

    vector<int> answer;

    for(int i = 0; i < m + n - 1; i++){
        if(i % 2 == 0){
            for(int j = diagonals[i].size() - 1; j >= 0; j--){
                answer.push_back(diagonals[i][j]);
            }
        }else{
            for(int j = 0; j < diagonals[i].size(); j++){
                answer.push_back(diagonals[i][j]);
            }
        }
    }

    return answer;
}

void printAnswer(const vector<int> &answer){
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i];

        if(i != answer.size() - 1)
            cout << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    if(m < 1 || m > 1000 || n < 1 || n > 1000 || 
        (long long)m * n < 1 || (long long)m * n > 1000000)
     return 0;

    vector<vector<int>> matrix(m, vector<int>(n));

    readMatrix(matrix, m, n);

    vector<int> answer = diagonalTraversal(matrix, m, n);

    printAnswer(answer);

    return 0;
}