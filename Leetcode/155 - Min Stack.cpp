class MinStack {
public:
    vector<pair<int,int>> v;
    
    MinStack() {
    }
    
    void push(int val) {
        if(v.size() == 0){
            v.push_back({val, v.size()});
        } else{
            pair<int,int> t = v[v.size()-1];
            pair<int,int> m = v[t.second];
            if(m.first > val){
                v.push_back({val, v.size()});
            } else {
                v.push_back({val, t.second});
            }
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        pair<int,int> t = v[v.size()-1];
        return t.first;
    }
    
    int getMin() {
        pair<int,int> t = v[v.size()-1];
        pair<int,int> m = v[t.second];
        return m.first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */