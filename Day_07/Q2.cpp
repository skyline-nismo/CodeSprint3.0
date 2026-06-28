#include <iostream>
using namespace std;

string compressString(string s){
    string compressed = "";
    for(int i = 0; i < s.length(); i++){
        char currentChar = s[i];
        int count = 1;
        while(i + 1 < s.length() && s[i] == s[i + 1]){
            count++;
            i++;
        }
        compressed += currentChar + to_string(count);
    }
    return compressed;
}

int main(){
    string s;
    cin >> s;
    if(s.length() < 1 || s.length() > 100000){
        return 0;
    }
    cout << compressString(s);
    return 0;
}