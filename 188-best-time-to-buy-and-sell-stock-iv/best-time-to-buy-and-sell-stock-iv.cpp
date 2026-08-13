class Solution {
public:
int solve(int idx,vector<int>& prices,bool hold,
vector<vector<vector<int>>>& dp,int k){
    if(idx == prices.size() || k == 0) return 0;
    int pick = 0,notpick = 0;
    if(dp[idx][hold][k] != -1) return dp[idx][hold][k];
    if(hold == false){
        pick = max(-prices[idx] + solve(idx+1,prices,true,dp,k),solve(idx+1,prices,false,dp,k));
    }
    else{
        notpick = max(prices[idx] + solve(idx+1,prices,false,dp,k - 1),solve(idx+1,prices,true,dp,k));
    }
    return dp[idx][hold][k] = max(pick,notpick);
}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k + 1,-1)));
        return solve(0,prices,false,dp,k);
    }
};