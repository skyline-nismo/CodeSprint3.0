#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaximumVisibilityScore(vector<int> &heights, int n){
    int left = 0, right = n - 1;
    int maxScore = 0;
    while(left < right){
        int currentHeight = min(heights[left], heights[right]);
        int distance = right - left;
        int currentScore = currentHeight * distance;
        maxScore = max(maxScore, currentScore);
        if(heights[left] < heights[right]){
            left++;
        }else{
            right--;
        }
    }
    return maxScore;
}

int main(){
    int n;
    cin >> n;
    if(n < 2 || n > 100){
        return 0;
    }
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
        if(heights[i] < 1 || heights[i] > 10000){
            return 0;
        }
    }
    cout << findMaximumVisibilityScore(heights, n);
    return 0;
}   