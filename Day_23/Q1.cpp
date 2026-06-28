#include <bits/stdc++.h>
using namespace std;

void buildSparseTables(vector<long long> &arr, int n,
                       vector<vector<long long>> &sparseMin,
                       vector<vector<long long>> &sparseMax,
                       vector<int> &logValues){
    logValues.resize(n + 1);
    logValues[1] = 0;
    for(int i = 2; i <= n; i++)
        logValues[i] = logValues[i / 2] + 1;
    int maxLog = logValues[n] + 1;
    sparseMin.assign(n, vector<long long> (maxLog));
    sparseMax.assign(n, vector<long long> (maxLog));    
    for(int i = 0; i < n; i++){
        sparseMin[i][0] = arr[i];
        sparseMax[i][0] = arr[i];
    }
    for(int j = 1; j < maxLog; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            sparseMin[i][j] = min(sparseMin[i][j - 1], sparseMin[i + (1 << (j - 1))][j - 1]);
            sparseMax[i][j] = max(sparseMax[i][j - 1], sparseMax[i + (1 << (j - 1))][j - 1]);
        }
    }
}

long long getRangeMin(int left, int right,
                      vector<vector<long long>> &sparseMin,
                      vector<int> &logValues){
    int length = right - left + 1;
    int k = logValues[length];
    return min(sparseMin[left][k], sparseMin[right - (1 << k) + 1][k]);
}

long long getRangeMax(int left, int right,
                      vector<vector<long long>> &sparseMax,
                      vector<int> &logValues){
    int length = right - left + 1;
    int k = logValues[length];
    return max(sparseMax[left][k], sparseMax[right - (1 << k) + 1][k]);
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100)
        return 0;
    vector<long long> temperature(n);
    for (int i = 0; i < n; i++){
        cin >> temperature[i];
        if(temperature[i] < -1000000000LL || temperature[i] > 1000000000LL)
            return 0;
    }
    int q;
    cin >> q;
    if(q < 1 || q > 100000)
        return 0;
    vector<vector<long long>> sparseMin;
    vector<vector<long long>> sparseMax;
    vector<int> logValues;
    buildSparseTables(temperature, n, sparseMin, sparseMax, logValues);
    while(q--){
        int l, r;
        cin >> l >> r;
        if (l < 0 || r < 0 || l > r || r >= n)
            return 0;
        long long minimumValue = getRangeMin(l, r, sparseMin, logValues);
        long long maximumValue = getRangeMax(l, r, sparseMax, logValues);
        cout << (maximumValue - minimumValue) << "\n";
    }
    return 0;
}