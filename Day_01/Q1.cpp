/*
Jagrit and the Magical Energy Stones
Problem Statement
"During an adventure in an ancient kingdom, Jagrit discovered a magical pathway filled with glowing energy stones. Each stone had a number written on it.

However, some stones had lost their power and showed the number 0.
The kingdom’s wizard gave Jagrit a task:

“Move all the powerless stones (0s) to the end of the pathway while keeping the order of the active stones exactly the same.”

Help Jagrit rearrange the stones correctly."

Input Format
The first line contains an integer N — the number of stones.

The second line contains N space-separated integers representing the stones.

Output Format
Print the updated arrangement after moving all zeroes to the end.


Example
Input
N = 7

Elements = 1 0 4 0 5 2 0

Output
1 4 5 2 0 0 0

Constraints
1 ≤ N ≤ 10^5
−10^9 ≤ elements ≤ 10^9

Hints (2)
1
Hint 1: Use two pointers. One pointer stays at the position where the next non-zero number should go, while the other loops through the array.

2
Hint 2: Whenever you see a non-zero number, move it forward. Once you finish checking all numbers, fill the remaining empty spots at the end with 0.
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
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            a[count] = a[i];
            count++;
        }
    }
    for(int i = count; i < n; i++){
        a[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}