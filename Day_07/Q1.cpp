#include <iostream>
using namespace std;

bool isLowercase(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] < 'a' || s[i] > 'z'){
            return false;
        }
    }
    return true;
}

bool areAnagrams(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }
    int freq[26] = {0};
    for(int i = 0; i < s1.length(); i++){
        freq[s1[i] - 'a']++;
    }
    for(int i = 0; i < s2.length(); i++){
        freq[s2[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(freq[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if(s1.length() < 1 || s1.length() > 100000 || 
        s2.length() < 1 || s2.length() > 100000){
        return 0;
    }
    if(!isLowercase(s1) || !isLowercase(s2)){
        return 0;
    }
    if(areAnagrams(s1, s2)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}