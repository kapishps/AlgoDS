class Solution {
public:
    unordered_map<int, int> m;
    
    int solve(int src){
        if(m.find(src) == m.end()){
            return 0;
        }
        if(m[src] == -1){
            m[src] = 1 + solve(src-1);
        }
        return m[src];
    }
    
    int longestConsecutive(vector<int>& nums) {
        for(auto i: nums){
            m[i] = -1;
        }
        
        int ans = 0, curr = 0;
        for(auto i: nums){
            if(m[i] == -1){
                curr = solve(i);
                ans = max(curr, ans);
            }
        }
        return ans;
        
    }
};