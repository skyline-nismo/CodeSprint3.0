#include <iostream>
using namespace std;

bool hasUppercase(string password){
    for(int i = 0; i < password.length(); i++){
        if(password[i] >= 'A' && password[i] <= 'Z'){
            return true;
        }
    }
    return false;
}

bool hasLowercase(string password){
    for(int i = 0; i < password.length(); i++){
        if(password[i] >= 'a' && password[i] <= 'z'){
            return true;
        }
    }
    return false;
}

bool hasDigit(string password){
    for(int i = 0; i < password.length(); i++){
        if(password[i] >= '0' && password[i] <= '9'){
            return true;
        }
    }
    return false;
}

int main(){
    string password;
    cin >> password;
    if(password.length() < 1 || password.length() > 100){
        return 0;
    }
    if(hasUppercase(password) &&
        hasLowercase(password) &&
        hasDigit(password)){
        cout << "STRONG";
    }else{
        cout << "WEAK";
    }
    return 0;
}