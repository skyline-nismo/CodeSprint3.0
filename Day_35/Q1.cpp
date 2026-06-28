#include <bits/stdc++.h>
using namespace std;

long long countEligibleStudents(vector<long long> &scores, long long k, int n){
    sort(scores.begin(), scores.end());
    vector<long long> prefix(n, 0);
    prefix[0] = scores[0];
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + scores[i];

    long long eligibleCount = 0;
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && scores[j] == scores[i])
            j++;

        long long sumOfSmallerScores = 0;
        if(i > 0)
            sumOfSmallerScores = prefix[i - 1];

        if(sumOfSmallerScores >= k)
            eligibleCount += (j - i);

        i = j;
    }
    return eligibleCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long k;
    cin >> n >> k;
    if(n < 1 || n > 100000 || k < 0LL || k > 1000000000000000LL) return 0;
    vector<long long> scores(n);
    for(int i = 0; i < n; i++){
        cin >> scores[i];
        if(scores[i] < 0LL || scores[i] > 1000000000LL) return 0;
    }
    cout << countEligibleStudents(scores, k, n);

    return 0;
}