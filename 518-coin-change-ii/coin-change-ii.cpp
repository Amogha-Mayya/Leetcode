class Solution {
public:
typedef unsigned long long ll;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ll>>dp(n+1,vector<ll>(amount+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                ll pick = 0;
                if(coins[i-1] <= j){
                    pick = dp[i][j - coins[i-1]];
                }
                ll notpick = dp[i-1][j];
                dp[i][j] = (pick + notpick);
            }
        }
        return (int)dp[n][amount];
    }
};