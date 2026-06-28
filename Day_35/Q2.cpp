#include <bits/stdc++.h>
using namespace std;

long long countUniqueBalancedPairs(vector<long long> &weights, long long x){
    sort(weights.begin(), weights.end());

    int left = 0;
    int right = weights.size() - 1;

    long long pairCount = 0;

    while(left < right){
        long long currentSum = weights[left] + weights[right];
        if(currentSum == x){
            pairCount++;

            long long leftValue = weights[left];
            long long rightValue = weights[right];

            while(left < right && weights[left] == leftValue)
                left++;

            while(left < right && weights[right] == rightValue)
                right--;
        }else if(currentSum < x){
            left++;
        }else{
            right--;
        }
    }

    return pairCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;

    cin >> n >> x;
    if(n < 1 || n > 100000 || x < 1LL || x > 1000000000000000LL) return 0;

    vector<long long> weights(n);

    for(int i = 0; i < n; i++){
        cin >> weights[i];
        if(weights[i] < 1LL || weights[i] > 1000000000LL) return 0;
    }
    cout << countUniqueBalancedPairs(weights, x);

    return 0;
}