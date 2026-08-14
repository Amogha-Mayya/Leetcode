class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1}
};
int solve(int x,int y,vector<vector<int>>& grid,int m,int n,
vector<vector<int>>& dp){
    if(x == m-1 && y == n-1) return grid[x][y];
    int ans = INT_MAX;
    if(dp[x][y] != -1) return dp[x][y];
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n){
            ans = min(ans,grid[x][y] + solve(xn,yn,grid,m,n,dp));
        }
    }
    return dp[x][y] = ans;
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,grid,m,n,dp);
    }
};