class Solution {
public:
typedef unsigned long long ll;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                ll take = 0;
                if(coins[i-1] <= j){
                    take = dp[i][j-coins[i-1]];
                }
                ll nottake = dp[i-1][j];
                dp[i][j] = (take + nottake);
            }
        }
        return (int)dp[n][amount];
    }
};