#include <bits/stdc++.h>
using namespace std;

int findLongestValidSubarray(vector<int> &tokens, int n,long long w){
    int left = 0;
    long long currentSum = 0;
    int maxLength = 0;
    for(int right = 0; right < n; right++){
        currentSum += tokens[right];
        while(currentSum > w){
            currentSum -= tokens[left];
            left++;
        }
        int currentLength = right - left + 1;
        maxLength = max(maxLength, currentLength);
    }
    return maxLength;
}
        
int main(){
    int n;
    long long w;
    cin >> n >> w;
    if(n < 1 || n > 100000 || w < 1 || w > 1000000000)
        return 0;
    vector<int> tokens(n);
    for(int i = 0; i < n; i++){
        cin >> tokens[i];
        if(tokens[i] < 1 || tokens[i] > 10000)
            return 0;
    }
    cout << findLongestValidSubarray(tokens, n, w);
    return 0;
}