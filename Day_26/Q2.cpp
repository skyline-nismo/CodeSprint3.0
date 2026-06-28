#include <bits/stdc++.h>
using namespace std;

long long totalMoves = 0;
void solveHanoi(int n, char source, char auxiliary, char destination){
    if (n == 1){
        cout << "Move plate 1 from " << source << " to " << destination << "\n";
        totalMoves++;
        return;
    }
    solveHanoi(n - 1, source, destination, auxiliary);
    cout << "Move plate " << n << " from " << source << " to " << destination << "\n";
    totalMoves++;
    solveHanoi(n - 1, auxiliary, source, destination);
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 15)
        return 0;
    solveHanoi(n, 'A', 'B', 'C');
    cout << "Total Moves = " << totalMoves << "\n";
    return 0;
}