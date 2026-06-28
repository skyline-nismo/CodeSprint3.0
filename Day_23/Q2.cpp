#include <bits/stdc++.h>
using namespace std;

bool isValidInput(int num){
    if(num < 1 || num > 100)
        return false;
    return true;
}

long long calculateRangeScore(const vector<int> &arr, int left, int right){
    unordered_map<int, int> frequency;
    for (int i = left; i <= right; i++)
        frequency[arr[i]]++;
    long long score = 0;
    for(auto &entry : frequency){
        long long freq = entry.second;
        score += freq * freq;
    }
    return score;
}

int main(){
    int n;
    cin >> n;
    if(!isValidInput(n))
        return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 1 || arr[i] > 1000000)
            return 0;
    }
    int q;
    cin >> q;
    if(!isValidInput(q))
        return 0;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l < 0 || r < 0 || l > r || r >= n)
            return 0;
        cout << calculateRangeScore(arr, l, r) << "\n";
    }
    return 0;
}