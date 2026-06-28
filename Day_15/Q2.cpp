#include <bits/stdc++.h>
using namespace std;

long long findMinMaxBoatLoad(vector<long long> &arr){
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    long long maxLoad = 0;
    while(left < right){
        long long sum = arr[left] + arr[right];
        if (sum > maxLoad){
            maxLoad = sum;
        }
        left++;
        right--;
    }
    return maxLoad;
}

int main(){
    int n;
    cin >> n;
    if(n < 2 || n > 2 * 100000 || n % 2 != 0){
        return 0;
    }
    vector<long long> weights(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
        if(weights[i] < 1 || weights[i] > 1000000000){
            return 0;
        }
    }
    cout << endl << findMinMaxBoatLoad(weights) << endl;
    return 0;
}