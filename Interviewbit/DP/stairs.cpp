int Solution::climbStairs(int A) {
    int dp[A+1];
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<A;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[A-1];
}
