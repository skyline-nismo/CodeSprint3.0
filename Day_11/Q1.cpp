#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int> &arr, int n){
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(vector<int> arr, int n){
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
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] != 0 && arr[i] != 1 && arr[i] != 2){
            return 0;
        }
    }
    sortArray(arr, n);
    printArray(arr, n);
    return 0;
}