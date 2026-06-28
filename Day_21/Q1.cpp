#include <bits/stdc++.h>
using namespace std;

void readElements(vector<int> &arr, int n){
    string line;
    int totalNodes = 0;
    for(int i = 0; i < n; i++){
        getline(cin, line);
        stringstream ss(line);
        int x;
        while(ss >> x){
            arr.push_back(x);
            totalNodes++;
            if(totalNodes > 100000)
                exit(0);
        }
    }
}

void printAnswer(const vector<int> &arr){
    for(int i = 0, n = arr.size(); i < n; i++){
        if(i > 0)
            cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000)
        return 0;
    cin.ignore();
    vector<int> arr;
    readElements(arr, n);
    sort(arr.begin(), arr.end());
    printAnswer(arr);
    return 0;
}