#include <bits/stdc++.h>
using namespace std;

bool isValidString(const string &s){
    for(char ch : s){
        if(!isalpha(ch)){
            return false;
        }
    }
    return true;
}

int countPremiumBadges(string jewels, string stones){
    bool present[128] = {false};
    for(char ch : jewels){
        present[ch] = true;
    }
    int count = 0;
    for(char ch : stones){
        if(present[ch]){
            count++;
        }
    }
    return count;
}

int main(){
    string jewels, stones;
    cin >> jewels >> stones;
    if(jewels.length() < 1 || jewels.length() > 50 ||
        stones.length() < 1 || stones.length() > 50 || 
        !isValidString(jewels) || !isValidString(stones)){
        return 0;
    }
    bool seen[128] = {false};
    for(char ch : jewels){
        if(seen[ch]){
            return 0;
        }
        seen[ch] = true;
    }
    cout << endl << countPremiumBadges(jewels, stones);
    return 0;
}