#include <bits/stdc++.h>
using namespace std;

bool isBurnoutDetected(int n, int k, long long x,const vector<int> &arr){
    long long windowSum = 0;
    int zeroCount = 0;
    for(int i = 0; i < k; i++){
        windowSum += arr[i];
        if(arr[i] == 0){
            zeroCount++;
        }
    }
    if(windowSum >= x && zeroCount == 0){
        return true;
    }
    for(int i = k; i < n; i++){
        windowSum -= arr[i - k];
        if(arr[i - k] == 0){
            zeroCount--;
        }
        windowSum += arr[i];
        if(arr[i] == 0){
            zeroCount++;
        }
        if(windowSum >= x && zeroCount == 0){
            return true;
        }
    }
    return false;
}

int main(){
    int n, k;
    long long x;
    cin >> n >> k >> x;
    if(n < 1 || n > 100000 || 
        k < 1 || k > n || 
        x < 1 || x > 1000000000){
        return 0;
    }
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 0 || arr[i] > 10000){
            return 0;
        }
    }
    cout << endl;
    cout << (isBurnoutDetected(n, k, x, arr) ? "YES" : "NO");
    return 0;
}