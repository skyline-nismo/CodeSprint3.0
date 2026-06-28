#include <bits/stdc++.h>
using namespace std;

struct CacheEntry{
    long long value;
    list<long long>::iterator pos;
};

class LRUCache{
    int capacity;
    list<long long> order;
    unordered_map<long long, CacheEntry> mp;
    void makeMostRecent(long long key){
        order.erase(mp[key].pos);
        order.push_front(key);
        mp[key].pos = order.begin();
    }
public:
    LRUCache(int cap){
        capacity = cap;
    }

    void put(long long key, long long value){
        if(mp.find(key) != mp.end()){
            mp[key].value = value;
            makeMostRecent(key);
            return;
        }
        if((int)order.size() == capacity){
            long long lruKey = order.back();
            order.pop_back();
            mp.erase(lruKey);
        }
        order.push_front(key);
        mp[key] = {value, order.begin()};
    }

    long long get(long long key){
        if(mp.find(key) == mp.end())
            return -1;
        makeMostRecent(key);
        return mp[key].value;
    }
};

bool isValidInput(int num){
    if(num < 1 || num > 100000)
        return false;
    return true;    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int capacity;
    cin >> capacity;
    if(!isValidInput(capacity))
        return 0;
    int q;
    cin >> q;
    if(!isValidInput(q))
        return 0;

    LRUCache cache(capacity);
    while(q--){
        string operation;
        cin >> operation;
        if(operation == "PUT"){
            long long key, value;
            cin >> key >> value;
            if(key < 1LL || key > 1000000000LL ||
                value < 1LL || value > 1000000000LL)
                return 0;
            cache.put(key, value);
        }else if(operation == "GET"){
            long long key;
            cin >> key;
            if(key < 1LL || key > 1000000000LL)
                return 0;
            cout << cache.get(key) << '\n';
        }
    }
    return 0;
}