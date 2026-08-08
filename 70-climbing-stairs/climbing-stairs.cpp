class Solution {
public:
int solve(int idx,int n,vector<int>& dp){
    if(idx == n){
        return 1;
    }
    if(dp[idx] != -1) return dp[idx];
    int pick1 = 0,pick2 = 0;
    if(idx + 1 <= n)
    pick1 = solve(idx+1,n,dp);
    if(idx + 2 <= n)
    pick2 = solve(idx+2,n,dp);
    return dp[idx] = (pick1 + pick2);
}
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(0,n,dp);
    }
};