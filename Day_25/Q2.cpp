#include <bits/stdc++.h>
using namespace std;

string findMinimumWindow(const string &s, const string &t){
    vector<int> required(256, 0);
    vector<int> window(256, 0);

    for(char ch : t){
        required[ch]++;
    }
    int requiredCount = t.length();
    int left = 0;
    int minLength = INT_MAX;
    int startIndex = -1;
    for(int right = 0; right < s.length(); right++){
        char currentChar = s[right];
        window[currentChar]++;
        if(required[currentChar] > 0 && 
            window[currentChar] <= required[currentChar]){
            requiredCount--;
        }
        while(requiredCount == 0){
            int currentWindowLength = right - left + 1;
            if(currentWindowLength < minLength){
                minLength = currentWindowLength;
                startIndex = left;
            }
            char leftChar = s[left];
            window[leftChar]--;
            if(required[leftChar] > 0 && 
                window[leftChar] < required[leftChar]){
                requiredCount++;
            }
            left++;
        }
    }
    if(startIndex == -1)
        return "-1";
    return s.substr(startIndex, minLength);
}

int main(){
    string s, t;
    cin >> s;
    if(s.length() < 1 || s.length() > 100000)
        return 0;
    cin >> t;
    if(t.length() < 1 || t.length() > s.length())
        return 0;
    cout << findMinimumWindow(s, t);
    return 0;
}