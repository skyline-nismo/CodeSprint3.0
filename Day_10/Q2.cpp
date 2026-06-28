#include <iostream>
#include <algorithm>
using namespace std;

bool hasTripletSum(int arr[], int n, int k){
    sort(arr, arr + n);
    for(int i = 0; i < n - 2; i++){
        int left = i + 1, right = n - 1;
        while(left < right){
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == k){
                return true;
            }else if(sum < k){
                left++;
            }else{
                right--;
            }
        }
    }
    return false;
}

int main(){
    int n, k;
    cin >> n;
    if(n < 1 || n > 100){
        return 0;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < -10000 || arr[i] > 10000){
            return 0;
        }
    }
    cin >> k;
    if(k < -10000 || k > 10000){
        return 0;
    }
    if(hasTripletSum(arr, n, k)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}