#include <bits/stdc++.h>
using namespace std;

void generateCombinations(int index,
                          const string &digits,
                          const vector<string> &mapping,
                          string current,
                          vector<string> &result){
    if(index == digits.length()){
        result.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];

    for(char ch : letters){
        generateCombinations(index + 1,
                             digits,
                             mapping,
                             current + ch,
                             result);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string digits;
    cin >> digits;
    if(digits.length() < 1 || digits.length() > 4) return 0;
    for(char ch : digits)
        if(ch < '2' || ch > '9') return 0;

    vector<string> mapping(10);

    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    vector<string> result;

    generateCombinations(0, digits, mapping, "", result);

    for(int i = 0; i < result.size(); i++){
        cout << result[i];

        if(i != result.size() - 1){
            cout << " ";
        }
    }

    return 0;
}