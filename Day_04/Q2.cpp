/*#include <iostream>
using namespace std;
void printRow(int row, int n){
    for(int i = 1; i <= row; i++){
        cout << i;
    }
    int atCount = 2 * (n - row);
    for(int i = 1; i <= atCount; i++){
        cout << "@";
    }
    for(int i = row; i >= 1; i--){
        cout << i;
    }
    cout << endl;
}

void printPattern(int n){
    for(int row = 1; row <= n; row++){
        printRow(row, n);
    }
}

int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 20){
        return 0;
    }
    printPattern(n);
    return 0;
}*/
#include <iostream>
using namespace std;
void printRow(int row, int n){
  for(int i = 1; i <= row; i++){
    cout << i;
  }
  int middle = 2 * (n - row);
  for(int i = 1; i <= middle; i++){
    cout << "@";
  }
  for(int i = row; i >= 1; i--){
    cout << i;
  }
  cout << endl;
}

void printPattern(int n){
  for(int row = 1; row <= n; row++){
    printRow(row, n);
  }
}

int main(){
  int n;
  cin >> n;
  if(n < 1 || n > 20){
    return 0;
  }
  printPattern(n);
  return 0;
}