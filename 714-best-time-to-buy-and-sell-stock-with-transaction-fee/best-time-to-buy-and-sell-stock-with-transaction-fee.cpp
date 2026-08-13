class Solution {
public:
int solve(int idx,vector<int>& prices,vector<vector<int>>& dp,
int hold,int fee){
    if(idx >= prices.size()) return 0;
    int pick = 0, notpick = 0;
    if(dp[idx][hold] != -1) return dp[idx][hold];
    if(hold == false)
    pick = max(-prices[idx] + solve(idx + 1,prices,dp,1,fee),solve(idx + 1,prices,dp,0,fee));
    else
    notpick = max(prices[idx] - fee + solve(idx + 1,prices,dp,0,fee),solve(idx + 1,prices,dp,1,fee));
    return dp[idx][hold] = max(pick,notpick);
}
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,prices,dp,0,fee);
    }
};