class Solution {
public:
    int dp[31][1005];
    int mod = 1e9+7;
    
    int solve(int n, int k, int target){
        if(target < 1){
            return 0;
        }
        if(n == 1){
            if(target <= k){
                return 1;
            } else {
                return 0;
            }
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i =1; i<= k; i++){
            ans = (ans + solve(n-1, k, target - i))%mod;
        }
        dp[n][target] = ans;
        return ans;
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        for(int i = 0; i<= min(n,30); i++){
            for(int j =0; j<= min(target,1000); j++){
                dp[i][j] = -1;
            }
        }
        return solve(n,k,target);
    }
};