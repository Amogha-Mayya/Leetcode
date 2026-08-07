class Solution {
public:
int solve(int idx,vector<int>& prices,bool have_share,int trans,
vector<vector<vector<int>>>& dp){
    if(idx == prices.size() || trans == 0) return 0;
    int buy = 0,sell = 0, hold = 0, wait = 0;
    if(dp[idx][have_share][trans] != -1) return dp[idx][have_share][trans];
    if(have_share == false){
    buy = -1 * prices[idx] + solve(idx+1,prices,true,trans,dp);
    wait = solve(idx+1,prices,false,trans,dp);
    }
    if(have_share == true){
    sell = prices[idx] + solve(idx+1,prices,false,trans-1,dp);
    hold = solve(idx+1,prices,true,trans,dp);
    }
    return dp[idx][have_share][trans] = max({buy,wait,sell,hold});
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,prices,false,k,dp);
    }
};