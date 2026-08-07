class Solution {
public:
vector<vector<int>>c = {
    {0,1},{1,0}
};
int solve(int x,int y,int m,int n,vector<vector<int>>& obstacleGrid,
vector<vector<int>>& dp){
    if(x == m-1 && y == n-1){
        return 1;
    }
    if(dp[x][y] != -1) return dp[x][y];
    int ans = 0;
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n && obstacleGrid[xn][yn] != 1){
            ans += solve(xn,yn,m,n,obstacleGrid,dp);
        }
    }
    return dp[x][y] = ans;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,obstacleGrid,dp);
    }
};