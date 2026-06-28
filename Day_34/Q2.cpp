#include <bits/stdc++.h>
using namespace std;

int findMaximumEnergy(int n, int x, 
    const vector<int> &cost, const vector<int> &energy){
    vector<int> dp(x + 1, 0);

    for(int coins = 1; coins <= x; coins++){
        for(int i = 0; i < n; i++){
            if(cost[i] <= coins){
                dp[coins] = max(dp[coins], dp[coins - cost[i]] + energy[i]);
            }
        }
    }

    return dp[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;

    // Constraint check for N and X
    if(n < 1 || n > 100 || x < 1 || x > 5000) return 0;

    vector<int> cost(n);
    vector<int> energy(n);

    for(int i = 0; i < n; i++){
        cin >> cost[i] >> energy[i];

        // Constraint check for each drink
        if (cost[i] < 1 || cost[i] > 100 || energy[i] < 1 || energy[i] > 1000) return 0;
    }
    cout << findMaximumEnergy(n, x, cost, energy);

    return 0;
}