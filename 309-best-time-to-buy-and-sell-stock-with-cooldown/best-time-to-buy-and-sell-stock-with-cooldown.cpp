class Solution {
public:
int solve(int idx,vector<int>& prices,vector<vector<int>>& dp,
int hold){
    if(idx >= prices.size()) return 0;
    int pick = 0, notpick = 0;
    if(dp[idx][hold] != -1) return dp[idx][hold];
    if(hold == false)
    pick = max(-prices[idx] + solve(idx + 1,prices,dp,1),solve(idx + 1,prices,dp,0));
    else
    notpick = max(prices[idx] + solve(idx + 2,prices,dp,0),solve(idx + 1,prices,dp,1));
    return dp[idx][hold] = max(pick,notpick);
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,prices,dp,0);
    }
};