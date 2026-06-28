#include <iostream>
using namespace std;
int findFullBatch(int arr[], int n, int x){
    int runningTotal = 0;
    for(int i = 0; i < n; i++){
        runningTotal += arr[i];
        if(runningTotal > x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, x;
    cin >> n;
    cin >> x;
    if(n < 1 || n > 100000 || x < 1 || x > 1000000000){
        return 0;
    }
    int arr [10000];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int answer = findFullBatch(arr, n, x);
    cout << answer << endl;
    return 0;
}