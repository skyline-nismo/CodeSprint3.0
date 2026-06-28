#include <iostream>
#include <algorithm>
using namespace std;

bool startsWith(string restaurant, string prefix){
    if(prefix.length() > restaurant.length()){
        return false;
    }
    for(int i = 0; i < prefix.length(); i++){
        if(restaurant[i] != prefix[i]){
            return false;
        }
    }
    return true;
}

void printMatchingRestaurants(string restaurants[], int n, string prefix){
    sort(restaurants, restaurants + n);
    bool found = false;
    for(int i = 0; i < n; i++){
        if(startsWith(restaurants[i], prefix)){
            cout << restaurants[i] << endl;
            found = true;
        }
    }
    if(!found){
        cout << -1 << endl;
    }
}

bool isLowercase(string s){
    for(char c : s){
        if(c < 'a' || c > 'z'){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100){
        return 0;
    }
    string restaurants[n], prefix;
    for(int i = 0; i < n; i++){
        cin >> restaurants[i];
        if(restaurants[i].length() < 1 || restaurants[i].length() > 100 || !isLowercase(restaurants[i])){
            return 0;
        }
    }
    cin >> prefix;
    if(!isLowercase(prefix)) {
        return 0;
    }   
    printMatchingRestaurants(restaurants, n, prefix);
    return 0;
}