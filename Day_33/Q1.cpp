#include <bits/stdc++.h>
using namespace std;

/* class Passenger{
public:
    long long passengerID;
    long long priority;
    int arrivalOrder;

    Passenger(long long id, long long pr, int order){
        passengerID = id;
        priority = pr;
        arrivalOrder = order;
    }
};

class Compare
{
public:
    bool operator()(const Passenger& a, const Passenger& b) const{
        // Higher priority boards first
        if(a.priority != b.priority)
            return a.priority < b.priority;

        // If priorities are equal, earlier arrival boards first
        return a.arrivalOrder > b.arrivalOrder;
    }
}; */

struct Passenger{
    long long passengerID;
    long long priority;
    int arrivalOrder;

    Passenger(long long id, long long pr, int order){
        passengerID = id;
        priority = pr;
        arrivalOrder = order;
    }
};

struct Compare{
    bool operator()(Passenger a, Passenger b){
        if(a.priority != b.priority)
            return a.priority < b.priority;
        return a.arrivalOrder > b.arrivalOrder;
    }
};

void getPassengers(priority_queue<Passenger, vector<Passenger>, Compare> &pq, 
    int n){
    for(int i = 0; i < n; i++){
        long long id, priority;
        cin >> id >> priority;
        if(id < 1LL || id > 1000000000LL || 
            priority < 1LL || priority > 1000000000LL)
            exit(0);

        pq.push(Passenger(id, priority, i));
    }
}

void printBoardingOrder(priority_queue<Passenger, vector<Passenger>, Compare> &pq){
    while(!pq.empty()){
        cout << pq.top().passengerID << "\n";
        pq.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n < 1 || n > 100000) return 0;
    priority_queue<Passenger, vector<Passenger>, Compare> pq;
    getPassengers(pq, n);
    printBoardingOrder(pq);

    return 0;
}