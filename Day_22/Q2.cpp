#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<long long> &arr, int left, int mid, int right){
    vector<long long> temp;
    int i = left;
    int j = mid + 1;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= right){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

void mergeSort(vector<long long> &arr, int left, int right){
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeArray(arr, left, mid, right);
}

int main(){
    int n;
    cin >> n;
    if (n < 1 || n > 100000)
        return 0;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < -1000000000LL || arr[i] > 1000000000LL)
            return 0;
    }
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}