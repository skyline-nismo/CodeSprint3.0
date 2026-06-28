#include <bits/stdc++.h>
using namespace std;

int findLongestConsecutiveSequence(const vector<long long> &serial_numbers){
    unordered_set<long long> numbers;

    for (long long num : serial_numbers)
        numbers.insert(num);

    int longestLength = 0;

    for(long long num : numbers){
        // Check if this is the start of a sequence
        if(numbers.find(num - 1) == numbers.end()){
            long long currentNumber = num;
            int currentLength = 1;

            while(numbers.find(currentNumber + 1) != numbers.end()){
                currentNumber++;
                currentLength++;
            }

            longestLength = max(longestLength, currentLength);
        }
    }

    return longestLength;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n < 0 || n > 100000) return 0;
    vector<long long> serial_numbers(n);

    for(int i = 0; i < n; i++){
        cin >> serial_numbers[i];
        if(serial_numbers[i] < -1000000000LL || serial_numbers[i] > 1000000000LL) return 0;
    }

    cout << findLongestConsecutiveSequence(serial_numbers);

    return 0;
}