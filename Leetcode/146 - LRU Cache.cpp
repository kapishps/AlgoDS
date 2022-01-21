class LRUCache {
private:
    list<pair<int,int>> ls;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int size;
public:
    
    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        if(this->m.find(key) != this->m.end()){
            int value = (this->m[key])->second;
            this->ls.erase(this->m[key]);
            this->ls.push_front({key, value});
            this->m[key] = this->ls.begin();
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(this->m.find(key) != this->m.end()){
            this->ls.erase(this->m[key]);
        } else{
            if(this->ls.size() >= this->size){
                this->m.erase(ls.rbegin()->first);
                this->ls.pop_back();
            }
        }
        this->ls.push_front({key, value});
        this->m[key] = this->ls.begin();
    }
};