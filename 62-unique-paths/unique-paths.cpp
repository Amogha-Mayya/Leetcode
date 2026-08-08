class Solution {
public:
vector<vector<int>>c = {
    {0,1},{1,0}
};
int solve(int row,int col,int m,int n,vector<vector<int>>& dp){
    if(row == m-1 && col == n-1){
        return 1;
    }
    if(dp[row][col] != -1) return dp[row][col];
    int ans = 0;
    for(int k=0;k<c.size();k++){
        int xn = row + c[k][0];
        int yn = col + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n){
            ans += solve(xn,yn,m,n,dp);
        }
    }
    return dp[row][col] = ans;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
    }
};