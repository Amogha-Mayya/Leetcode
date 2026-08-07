class Solution {
public:
int solve(int idx1,int idx2,string word1,string word2){
    if(idx1 == word1.size()) return word2.size() - idx2;
    if(idx2 == word2.size()) return word1.size() - idx1;

    if(word1[idx1] == word2[idx2]){
        return solve(idx1+1,idx2+1,word1,word2);
    }
    else{
        return 1 + min({solve(idx1+1,idx2,word1,word2),solve(idx1,idx2+1,word1,word2),solve(idx1+1,idx2+1,word1,word2)});
    }
}
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0] = i;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n1][n2];
    }
};