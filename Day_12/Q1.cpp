#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void findClosestPair(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int firstElement = arr[left], secondElement = arr[right];
    while(left < right){
        int currentSum = arr[left] + arr[right];
        if(abs(currentSum) < abs(minSum)){
            minSum = currentSum;
            firstElement = arr[left];
            secondElement = arr[right];
        }
        if(currentSum < 0){
            left++;
        }else{
            right--;
        }
    }
    cout << firstElement << " " << secondElement << endl;
}
int main(){
    int n;
    cin >> n;
    if(n < 2 || n > 100){
        return 0;
    }
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < -100000 || arr[i] > 100000){
            return 0;
        }
    }
    findClosestPair(arr, n);
    return 0;
}