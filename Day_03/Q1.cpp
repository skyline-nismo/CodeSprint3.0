#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int codes[n];
    for(int i = 0; i < n; i++){
        cin >> codes[i];
    }
    //bool found = false;
    int found = 0;
    for(int i = 0; i <= n; i++){
        if(codes[i] == codes[i + 1]){
            cout << "INVALID " << i+1;
            //found = true;
            found = 1;
            break;
        }
    }
    if(!found){
        cout << "VALID";
    }
    return 0;
}