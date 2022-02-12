#include <list>

list<pair<int,int>> l;
unordered_map<int, list<pair<int,int>>::iterator> m;
int capacity;
    
LRUCache::LRUCache(int capacity) {
    ::capacity = capacity;
    l.clear();
    m.clear();
}

int LRUCache::get(int key) {
    if(m.find(key) != m.end()){
        int val = m[key]->second;
        l.erase(m[key]);
        l.push_front({key,val});
        m[key] = l.begin();
        return val;
    } else {
        return -1;
    }
}

void LRUCache::set(int key, int value) {
    if(m.find(key) != m.end()){
        l.erase(m[key]);
    } else {
        if(l.size() >= ::capacity){
            m.erase(l.rbegin()->first);
            l.pop_back();
        }
    }
    l.push_front({key,value});
    m[key] = l.begin();
}
