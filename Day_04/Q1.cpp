#include <iostream>
#include <string>
using namespace std;
bool isVowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        return true;
    }
    return false;
}

bool isAlphabet(char ch){
    if((ch >= 'A' && ch <= 'Z') || 
        (ch >= 'a' && ch <= 'z')){
        return true;
    }
    return false;
}

int countVowels(string str){
    int vowels = 0;
    for(int i = 0; i < str.length(); i++){
        if(isAlphabet(str[i]) && isVowel(str[i])){
            vowels++;
        }
    }
    return vowels;
}

int countConsonants(string str){
    int consonants = 0;
    for(int i = 0; i < str.length(); i++){
        if(isAlphabet(str[i]) && !isVowel(str[i])){
            consonants++;
        }
    }
    return consonants;
}

int countWords(string str){
    int words = 0;
    bool inWord = false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' ' && inWord == false){
            words++;
            inWord = true;
        }else if(str[i] == ' '){
            inWord = false;
        }
    }
    return words;
}

int main(){
    string sentence;
    getline(cin, sentence);
    if(sentence.length() < 1 || sentence.length() > 200){
        return 0;
    }
    int vowels = countVowels(sentence);
    int consonants = countConsonants(sentence);
    int words = countWords(sentence);
    cout << "Total Vowels: " << vowels << endl;
    cout << "Total Consonants: " << consonants << endl;
    cout << "Total Words: " << words << endl;
    return 0;
}