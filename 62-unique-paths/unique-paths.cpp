class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1}
};
int solve(int x,int y,int m,int n,vector<vector<int>>& dp){
    if(x == m-1 && y == n-1) return 1;
    int count = 0;
    if(dp[x][y] != -1) return dp[x][y];
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n){
            count += solve(xn,yn,m,n,dp); 
        }
    }
    return dp[x][y] = count;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp);
    }
};