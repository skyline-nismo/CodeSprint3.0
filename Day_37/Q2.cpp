#include <bits/stdc++.h>
using namespace std;

long long countSubarraysWithSumK(const vector<int> &array, long long k){
    unordered_map<long long, long long> prefixSumFrequency;

    long long currentPrefixSum = 0;
    long long totalSubarrays = 0;

    prefixSumFrequency[0] = 1;

    for(int value : array){
        currentPrefixSum += value;

        long long requiredPrefixSum = currentPrefixSum - k;

        if(prefixSumFrequency.find(requiredPrefixSum) != prefixSumFrequency.end())
            totalSubarrays += prefixSumFrequency[requiredPrefixSum];

        prefixSumFrequency[currentPrefixSum]++;
    }

    return totalSubarrays;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    if(n < 1 || n > 100000 || k < -10000000LL || k > 10000000LL) return 0;
    vector<int> array(n);
    for(int i = 0; i < n; i++){
        cin >> array[i];
        if(array[i] < -1000 || array[i] > 1000) return 0;
    }

    cout << countSubarraysWithSumK(array, k);

    return 0;
}