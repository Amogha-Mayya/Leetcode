class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(),0);
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            int pick1 = 1e9,pick2 = 1e9,pick3 = 1e9;
            if(i - 1 >= 0)
            pick1 = costs[i] + 1 + dp[i-1];
            if(i - 2 >= 0)
            pick2 = costs[i] + 4 + dp[i-2];
            if(i - 3 >= 0)
            pick3 = costs[i] + 9 + dp[i-3];
            dp[i] = min({pick1,pick2,pick3});
        }
        return dp[n];
    }
};