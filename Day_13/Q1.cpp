#include <iostream>
#include <vector>
using namespace std;

long long insertionSortAndCountShifts(vector<long long> &arr, int n){
    long long shifts = 0;
    for(int i = 1; i < n; i++){
        long long key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }
        arr[j + 1] = key;
    }
    return shifts;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100){
        return 0;
    }
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 1 || arr[i] > 1000000000){
            return 0;
        }
    }
    long long shifts = insertionSortAndCountShifts(arr, n);
    for(int i = 0; i < arr.size(); i++){
        if (i > 0){
            cout << " ";
        }
        cout << arr[i];
    }
    cout << endl;
    cout << shifts << endl;
    return 0;
}