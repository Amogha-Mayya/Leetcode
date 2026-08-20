class Solution {
public:
    int longestContinuousSubstring(string s) {
        string s1 = "abcdefghijklmnopqrstuvwxyz";
        string s2 = s;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = 0;
            }
        }
        int maxi = 0;
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                maxi = max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};