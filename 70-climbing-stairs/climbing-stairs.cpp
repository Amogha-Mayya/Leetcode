class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int pick1 = 0, pick2 = 0;
            if(i - 1 >=0)
                pick1 = dp[i-1];
            if(i - 2 >=0)
                pick2 = dp[i-2];
            dp[i] = pick1 + pick2;
        }
        return dp[n];
    }
};