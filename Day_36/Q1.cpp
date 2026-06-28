#include <bits/stdc++.h>
using namespace std;

int findRank(const vector<int> &marks, const int &target){
    int left = 0;
    int right = marks.size() - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(marks[mid] == target){
            return mid + 1; // Rank is 1-based
        }else if(marks[mid] < target){
            right = mid - 1; // Descending order
        }else{
            left = mid + 1;
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n < 1 || n > 100000) return 0;
    vector<int> marks(n);
    for(int i = 0; i < n; i++){
        cin >> marks[i];
        if(marks[i] < 0 || marks[i] > 1000) return 0;
    }
    int q;
    cin >> q;
    if(q < 1 || q > 100000) return 0;

    sort(marks.begin(), marks.end(), greater<int>());
    while(q--){
        int scores;
        cin >> scores;

        int rank = findRank(marks, scores);
        cout << (rank == -1 ? "No Rank" : "Rank " + to_string(rank));
        cout << "\n";
    }

    return 0;
}