#include <iostream>
using namespace std;

void sortedSquares(int arr[], int result[], int n){
  int left = 0, right = n - 1, index = n - 1;
  while(left <= right){
    int leftSquare = arr[left] * arr[left];
    int rightSquare = arr[right] * arr[right];
    if(leftSquare > rightSquare){
      result[index] = leftSquare;
      left++;
    }else{
      result[index] = rightSquare;
      right--;
    }
    index--;
  }
}

int main(){
  int n;
  cin >> n;
  if(n < 1 || n > 100000){
    return 0;
  }
  int arr[n], result[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(arr[i] < -10000 || arr[i] > 10000){
      return 0;
    }
  }
  sortedSquares(arr, result, n);
  for(int i = 0; i < n; i++){
    cout << result[i] << " ";
  }
  return 0;
}