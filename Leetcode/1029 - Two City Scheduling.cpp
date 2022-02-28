class Solution {
public:
    struct compare{
        bool operator()(const vector<int> &p1, const vector<int> &p2){
            return (p1[0]-p1[1]) < (p2[0]-p2[1]);
        }
    };
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare());
        
        int ans = 0;
        for(int i =0; i < (costs.size()/2); i++){
            ans += costs[i][0];
            ans += costs[i + (costs.size()/2)][1];
        }
        return ans;
    }
};