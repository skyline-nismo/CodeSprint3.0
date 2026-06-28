#include <bits/stdc++.h>
using namespace std;

vector<long long> getKLargestElements(vector<long long> &arr, int k){
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for(long long value : arr){
        minHeap.push(value);

        if((int)minHeap.size() > k)
            minHeap.pop();
    }

    vector<long long> result;

    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    sort(result.begin(), result.end());

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k;
    cin >> n >> k;
    if(n < 1 || n > 100000 || k < 1 || k > n) return 0;

    vector<long long> priorities(n);

    for(int i = 0; i < n; i++){
        cin >> priorities[i];
        if(priorities[i] < 1LL || priorities[i] > 1000000000LL) return 0;
    }

    vector<long long> answer = getKLargestElements(priorities, k);

    for(int i = 0; i < (int)answer.size(); i++){
        if(i > 0)
            cout << " ";
        cout << answer[i];
    }

    return 0;
}