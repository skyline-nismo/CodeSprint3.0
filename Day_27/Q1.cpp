#include <bits/stdc++.h>
using namespace std;

/* bool isBitonic(const vector<long long> &signals, int n){
    int peak = -1;
    for(int i = 1; i < n - 1; i++){
        if(signals[i] > signals[i - 1] && signals[i] > signals[i + 1]){
            if(peak != -1)
                return false;
            peak = i;
        }
    }
    if(peak == -1) return false;

    if(peak == 0 || peak == n - 1) return false;

    for(int i = 1; i <= peak; i++)
        if(signals[i] <= signals[i - 1]) return false;

    for(int i = peak + 1; i < n; i++)
        if (signals[i] >= signals[i - 1]) return false;
    return true;
} */

long long findPeakTransmission(const vector<long long> &signals, int n){
    int low = 0;
    int high = n - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        signals[mid] < signals[mid + 1] ? low = mid + 1 : high = mid;
    }
    return signals[low];
}

int main(){
    int n;
    cin >> n;
    if(n < 3 || n > 100000) return 0;
    vector<long long> signals(n);
    for(int i = 0; i < n; i++){
        cin >> signals[i];
        if(signals[i] < 1LL || signals[i] > 1000000000LL) return 0;
    }
    // if(!isBitonic(signals, n)) return 0;
    cout << findPeakTransmission(signals, n);
    return 0;
}