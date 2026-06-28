#include <iostream>
#include <string>
using namespace std;

string findLongestCommonPrefix(string arr[], int n){
    string prefix = arr[0];
    for(int i = 1; i < n; i++){
        string temp = "";
        for(int j = 0; j < prefix.length() && j < arr[i].length(); j++){
            if(prefix[j] == arr[i][j]){
                temp += prefix[j];
            }else{
                break;
            }
        }
        prefix = temp;
        if(prefix == ""){
            return "";
        }
    }
    return prefix;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100){
        return 0;
    }
    string arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i].length() < 1 || arr[i].length() > 10000){
            return 0;
        }
    }
    cout << findLongestCommonPrefix(arr, n);
    return 0;
}