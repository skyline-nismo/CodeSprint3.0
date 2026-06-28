#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

struct Participant{
    string name;
    int score;
};

bool isValidName(string name){
    if(name.length() < 1 || name.length() > 50){
        return false;
    }
    for(int i = 0; i < name.length(); i++){
        if(!isalpha(name[i])){
            return false;
        }
    }
    return true;
}

bool inputParticipants(vector<Participant> &arr, int n){
    for(int i = 0; i < n; i++){
        cin >> arr[i].name >> arr[i].score;
        if(!isValidName(arr[i].name)){
            return false;
        }
        if(arr[i].score < 0 || arr[i].score > 1000000){
            return false;
        }
    }
    return true;
}

void BubbleSort(vector<Participant> &arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j].score > arr[j + 1].score){
                Participant temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printLeaderboard(vector<Participant> arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i].name << " " << arr[i].score << endl;
    }
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100){
        return 0;
    }
    vector<Participant> arr(n);
    if(!inputParticipants(arr, n)){
        return 0;
    }
    BubbleSort(arr, n);
    printLeaderboard(arr, n);
    return 0;
}