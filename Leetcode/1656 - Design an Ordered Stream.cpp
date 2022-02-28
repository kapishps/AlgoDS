class OrderedStream {
public:
    vector<string> stream;
    int curr = 1;
    
    OrderedStream(int n) {
        stream.resize(n+2);
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        vector<string> ans;
        while(stream[curr].size() == 5){
            ans.push_back(stream[curr]);
            curr++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */