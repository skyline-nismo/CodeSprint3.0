#include <bits/stdc++.h>
using namespace std;

long long findMaximumArea(const vector<int> &heights, int n){
    int left = 0;
    int right = n - 1;
    long long maxArea = 0;
    while (left < right){
        long long height = min(heights[left], heights[right]);
        long long width = right - left;
        long long currentArea = height * width;
        maxArea = max(maxArea, currentArea);
        (heights[left] < heights[right]) ? left++ : right--;
    }
    return maxArea;
}

int main(){
    int n;
    cin >> n;
    if(n < 2 || n > 100000)
        return 0;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
        if(heights[1] < 0 || heights[i] > 10000)
            return 0;
    }
    cout << findMaximumArea(heights, n);
    return 0;
}