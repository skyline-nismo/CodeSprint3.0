#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getWords(const string &s){
    vector<string> words;
    int i = 0;
    while(i < s.size()){
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        int start = i;
        while(i < s.size() && s[i] != ' '){
            i++;
        }
        if(start < i){
            words.push_back(s.substr(start, i - start));
        }
    }
    return words;
}

void printReversedWords(const vector<string> &words){
    for(int i = words.size() - 1; i >= 0; i--){
        cout << words[i];
        if(i > 0){
            cout << ' ';
        }
    }
}

int main(){
    string s;
    getline(cin, s);
    if(s.size() < 1 || s.size() > 100000){
        return 0;
    }
    for(char c : s){
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              c == ' ')) {
            return 0;
        }
    }
    vector<string> words = getWords(s);
    if(words.empty()){
        return 0;
    }
    printReversedWords(words);
    return 0;
}