#include <bits/stdc++.h>
using namespace std;

bool isLowercase(string s){
    for(char ch : s){
        if(ch < 'a' || ch > 'z'){
            return false;
        }
    }
    return true;
}

int countVowels(string s){
    int count = 0;
    for(char ch : s){
        if(ch == 'a' || 
            ch == 'e' || 
            ch == 'i' || 
            ch == 'o' || 
            ch == 'u'){
            count++;
        }
    }
    return count;
}

bool compareUsernames(string a, string b){
    int vowelsA = countVowels(a), vowelsB = countVowels(b);
    if(vowelsA != vowelsB){
        return vowelsA > vowelsB;
    }
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100){
        return 0;
    }
    vector<string> usernames(n);
    for(int i = 0; i < n; i++){
        cin >> usernames[i];
        if(usernames[i].length() < 1 || usernames[i].length() > 100 || !isLowercase(usernames[i])){
            return 0;
        }
    }
    cout << endl;
    sort(usernames.begin(), usernames.end(), compareUsernames);
    for(string username : usernames){
        cout << username << endl;
    }
    return 0;
}