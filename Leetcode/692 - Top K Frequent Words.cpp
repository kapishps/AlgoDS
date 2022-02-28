class Solution {
public:
    struct compare {
        bool operator()(const pair<int,string> &p1, const pair<int,string> &p2){
            if(p1.first > p2.first){
                return true;
            } else if(p1.first == p2.first){
                return p1.second < p2.second;
            } else {
                return false;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;
        
        for(auto i: words){
            m[i]++;
        }
        
        for(auto i: m){
            pq.push({i.second, i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<string> ans;
        while(!pq.empty()){
            pair<int,string> t = pq.top();
            ans.push_back(t.second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};