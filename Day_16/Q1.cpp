#include <bits/stdc++.h>
using namespace std;

int countPremiumBadges(string jewels, string stones){
    unordered_set<char> premiumTypes(jewels.begin(), jewels.end());
    int count = 0;
    for(char ch : stones){
        if(premiumTypes.find(ch) != premiumTypes.end()){
            count++;
        }
    }
    return count;
}

bool isValidString(const string &s){
    for(char ch : s){
        if(!isalpha(ch)){  // Only English letters allowed
            return false;
        }
    }
    return true;
}

int main(){
    string jewels, stones;
    cin >> jewels >> stones;
    if(jewels.length() < 1 || jewels.length() > 50 ||
        stones.length() < 1 || stones.length() > 50){
        cout << "Invalid input";
        return 0;
    }
    if(!isValidString(jewels) || !isValidString(stones)){
        cout << "Invalid input";
        return 0;
    }
    unordered_set<char> uniqueJewels(jewels.begin(), jewels.end());
    if(uniqueJewels.size() != jewels.length()){
        cout << "Invalid input";
        return 0;
    }
    cout << countPremiumBadges(jewels, stones);
    return 0;
}