#include <iostream>
#include <vector>
using namespace std;

int selectionSortAndCountSwaps(vector<long long> &arr, int n){
    int swapCount = 0;
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[i], arr[minIndex]);
            swapCount++;
        }
    }
    return swapCount;
}

void printArray(const vector<long long> arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
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
    int swapCount = selectionSortAndCountSwaps(arr, n);
    printArray(arr, n);
    cout << swapCount << endl;
    return 0;
}