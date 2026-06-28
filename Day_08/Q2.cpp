#include <iostream>
using namespace std;

int findFinalXOR(int arr[], int n){
    int xorValue = 0;
    for(int i = 0; i < n; i++){
        xorValue ^= arr[i];
    }
    return xorValue;
}

int main(){
    int n;
    cin >> n;
    if (n < 1 || n > 100000){
        return 0;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 1000000000){
            return 0;
        }
    }
    int result = findFinalXOR(arr, n);
    if (result == 0){
        cout << "BALANCED";
    }else{
        cout << "UNBALANCED";
    }
    return 0;
}