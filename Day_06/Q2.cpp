#include <iostream>
using namespace std;

int mainDiagonalSum(int matrix[][50], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += matrix[i][i];
    }
    return sum;
}

int secondaryDiagonalSum(int matrix[][50], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 50){
        return 0;
    }
    int matrix[50][50];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] < -1000 || matrix[i][j] > 1000){
                return 0;
            }
        }
    }
    int mainSum = mainDiagonalSum(matrix, n);
    int secondarySum = secondaryDiagonalSum(matrix, n);
    if(mainSum == secondarySum){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}