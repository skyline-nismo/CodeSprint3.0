#include <bits/stdc++.h>
using namespace std;

void findUniqueAndPosition(const vector<int> &arr, int &uniqueNum, int &position){
    vector<int> freq(101, 0);

    // Step 1: Frequency count
    for(int x : arr)
        freq[x]++;

    // Step 2: Find unique number
    for(int i = 1; i <= 100; i++){
        if(freq[i] == 1){
            uniqueNum = i;
            break;
        }
    }

    // Step 3: Compute position in sorted array
    int countSmallerElements = 0;

    for(int i = 1; i < uniqueNum; i++)
        countSmallerElements += freq[i];

    position = countSmallerElements + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n < 1 || n > 100000 || n % 2 == 0) return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 1 || arr[i] > 100) return 0;
    }

    int uniqueNum = 0, position = 0;

    findUniqueAndPosition(arr, uniqueNum, position);

    cout << uniqueNum << " " << position << "\n";

    return 0;
}