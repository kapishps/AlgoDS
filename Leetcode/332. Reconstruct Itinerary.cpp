class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> ans;
    
    void dfs(string src){
        while(graph[src].size() > 0){
            auto i = graph[src].begin();
            string t = *i;
            graph[src].erase(i);
            dfs(t);
        }
        // IMPORTANT: for/for auto doesnt work
        // for(auto it = graph[src].begin(); it != graph[src].end(); it++){
        //     string t = *it;
        //     graph[src].erase(it);
        //     dfs(t);
        // }
        ans.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {     
        for(auto i: tickets){
            graph[i[0]].insert(i[1]);
        }
        
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};