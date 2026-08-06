class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n1 = s.size();
        int n2 = n1;
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};