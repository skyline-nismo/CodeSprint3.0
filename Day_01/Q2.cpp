/*
Ritrisha and the Exam Marks Mystery
easy
Problem Statement
"After the final exams were over, Ritrisha received her marks for all subjects.
While checking the report card, she became curious to know something interesting.

She wondered: “Did I score the same marks in any two subjects?”

Your task is to help Ritrisha determine whether there are any duplicate marks in her report card."

Input Format
The first line contains an integer N — the number of subjects.
The second line contains N space-separated integers representing the marks obtained in each subject.

Output Format
Print "YES" if any duplicate marks exist.
Otherwise, print "NO".


Example
Input
N = 6

Marks = 78 85 91 78 88 95

Output
YES

Constraints
1 ≤ N ≤ 10^5
0 ≤ marks ≤ 100

Hints (1)
1
Hint 1: If you encounter a mark that your tracking array says you've already seen, you instantly have your answer: print YES and break early!
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int dup = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] == a[j]){
                dup = 1;
                break;
            }
        }
        if(dup == 1){
            break;
        }
    }
    if(dup == 1){
        cout << "YES";
    } 
    else{
        cout << "NO";
    }
    return 0;
}