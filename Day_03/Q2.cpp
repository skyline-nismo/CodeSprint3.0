#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char ch = 'A' + i;
        for(int j = 0; j < n; j++){
            if(j == i || j == n - i - 1){
                cout << ch;
            } else {
                cout << "*";
            }
            if(j != n - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}