#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int largest = a[n - 1], second_largest;
    for(int i = n - 2; i >= 0; i--){
        if(a[i] != largest){
            second_largest = a[i];
            break;
        }
    }
    cout << second_largest;
    return 0;
}