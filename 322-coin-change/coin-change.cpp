class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=1;i<=amount;i++){
            dp[0][i] = 1e9;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int pick = 1e9;
                if(coins[i-1] <= j){
                    pick = 1 + dp[i][j - coins[i-1]];
                }
                int notpick = dp[i-1][j];
                dp[i][j] = min(pick,notpick);
            }
        }
        return (dp[n][amount] == 1e9)? -1 : dp[n][amount];
    }
};