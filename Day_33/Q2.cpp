#include <bits/stdc++.h>
using namespace std;

void findSlidingWindowMaximum(const vector<long long> &value, int n, int k){
    deque<int> dq;
    for(int i = 0; i < n; i++){
        // Remove indices that are outside the current window
        while(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while(!dq.empty() && value[dq.back()] <= value[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        // Start printing once the first window is formed
        if(i >= k - 1){
            cout << value[dq.front()];

            if(i != n - 1)
                cout << " ";
        }
    }

    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    if(n < 1 || n > 100000 || 
        k < 1 || k > n)
        return 0;
    vector<long long> value(n);
    for(int i = 0; i < n; i++){
        cin >> value[i];
        if(value[i] < 0LL || value[i] > 1000000000LL) return 0;
    }
    findSlidingWindowMaximum(value, n, k);

    return 0;
}