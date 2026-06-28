#include <iostream>
using namespace std;
const int MAX = 50;
bool hasOccupiedNeighbour(int library[][MAX], int row, int col, int n){
    if(row > 0 && library[row - 1][col] == 1){
        return true;
    }
    if(row < n - 1 && library[row + 1][col] == 1){
        return true;
    }
    if(col > 0 && library[row][col - 1] == 1){
        return true;
    }
    if(col < n - 1 && library[row][col + 1] == 1){
        return true;
    }
    return false;
}

void printLibraryStatus(int library[][MAX], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(library[i][j] == 1){
                cout << "O ";
            }else{
                if(hasOccupiedNeighbour(library, i, j, n)){
                    cout << "X ";
                }else{
                    cout << "S ";
                }
            }
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 50){
        return 0;
    }
    int library[MAX][MAX];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> library[i][j];
        }
    }
    printLibraryStatus(library, n);
    return 0;
}