class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0, j = 0;
        priority_queue<int, vector<int>> pq;
        for(int i =0; i< target; i++){
            while(j < stations.size() && stations[j][0] <= i){
                pq.push(stations[j][1]);
                j++;
            }
            if(startFuel == i){
                if(pq.empty()){
                    return -1;
                }
                startFuel += pq.top();
                pq.pop();
                ans++;
            }
            i = startFuel -1;   // saves TLE
        }
        return ans;
    }
};