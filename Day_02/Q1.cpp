#include <iostream>
using namespace std;
int main(){
    int n, sum = 0;
    cin >> n;
    int scores[n];
    for(int i = 0; i < n; i++){
        cin >> scores[i];
        sum += scores[i];
    }
    float avg = sum / n;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(scores[i] > avg){
            count++;
        }
    }
    cout << count;
    return 0;
}