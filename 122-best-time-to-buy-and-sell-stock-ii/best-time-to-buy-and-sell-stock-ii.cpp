class Solution {
public:
int solve(int idx,vector<int>& prices,bool have_share,
vector<vector<int>>& dp){
    if(idx == prices.size()) return 0;
    int buy = 0,sell = 0, hold = 0, wait = 0;
    if(dp[idx][have_share] != -1) return dp[idx][have_share];
    if(have_share == false){
    buy = -1 * prices[idx] + solve(idx+1,prices,true,dp);
    wait = solve(idx+1,prices,false,dp);
    }
    if(have_share == true){
    sell = prices[idx] + solve(idx+1,prices,false,dp);
    hold = solve(idx+1,prices,true,dp);
    }
    return dp[idx][have_share] = max({buy,wait,sell,hold});
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,prices,false,dp);
    }
};