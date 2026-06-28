#include <iostream>
using namespace std;

string expandAroundCenter(string &s, int left, int right){
    while(left >= 0 && right < s.length() && s[left] == s[right]){
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s){
    string result = "";
    for(int i = 0; i < s.length(); i++){
        string odd = expandAroundCenter(s, i, i);
        string even = expandAroundCenter(s, i, i + 1);
        if(odd.length() > result.length()){
            result = odd;
        }
        if(even.length() > result.length()){
            result = even;
        }
    }
    return result;
}

int main(){
    string s;
    cin >> s;
    if(s.length() < 1 || s.length() > 10000){
        return 0;
    }
    for(char c : s){
        if(c < 'a' || c > 'z'){
            return 0;
        }
    }
    cout << longestPalindrome(s) << endl;
    return 0;
}