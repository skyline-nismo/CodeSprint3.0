#include <iostream>
using namespace std;

int countSetBits(int number){
    int count = 0;
    while(number > 0){
        if(number % 2 == 1){
            count++;
        }
        number /= 2;
    }
    return count;
}

bool isOddParity(int number){
    int setBits = countSetBits(number);
    if(setBits % 2 == 1){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000){
        return 0;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 0 || arr[i] > 1000000000){
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(isOddParity(arr[i])){
            cout << "ANSWER" << endl;
        }else{
            cout << "SAFE" << endl;
        }
    }
    return 0;
}