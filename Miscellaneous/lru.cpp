#include<bits/stdc++.h>
using namespace std;

class LRU{
    list<int> li;
    unordered_map<int, list<int>::iterator> mp;
    int capacity;

public:
    LRU(int csize){
        capacity = csize;
    }

    bool isPresent(int key){
        if(mp.find(key)==mp.end()){
            cout<<endl<<"MISS"<<endl;
            return false;
        }
        cout<<endl<<"HIT"<<endl;
        return true;
    }

    void refer(int key){
        if(isPresent(key)){
            auto itr = mp[key];
            li.erase(itr);
        }
        else{
            if(li.size()==capacity){
                int data = li.back();
                li.pop_back();
                mp.erase(data);
            }
          
        }
          
        li.push_front(key);
        mp[key] = li.begin();
    }

    void printCache(){
        cout<<"Cache : ";
        for(auto i : li){
            cout<<i<<" ";
        }
        cout<<endl;
    }

};

int main(){
    LRU cache(4);
    cache.printCache();
    cache.refer(1);
    cache.printCache();
    cache.refer(2);
    cache.printCache();
    cache.refer(3);
    cache.printCache();
    cache.refer(1);
    cache.printCache();
    cache.refer(4);
    cache.printCache();
    cache.refer(2);
    cache.printCache();
    cache.refer(6);
    cache.printCache();
    cache.refer(8);
    cache.printCache();
    cache.refer(3);
    cache.printCache();
}