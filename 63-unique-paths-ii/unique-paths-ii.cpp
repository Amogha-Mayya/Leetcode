class Solution {
public:
vector<vector<int>>c = {
    {0,1},{1,0}
};
int solve(int row,int col,int m,int n,vector<vector<int>>& dp,
vector<vector<int>>& obstacleGrid){
    if(row == m-1 && col == n-1){
        return 1;
    }
    if(dp[row][col] != -1) return dp[row][col];
    int ans = 0;
    for(int k=0;k<c.size();k++){
        int xn = row + c[k][0];
        int yn = col + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n && obstacleGrid[xn][yn] == 0){
            ans += solve(xn,yn,m,n,dp,obstacleGrid);
        }
    }
    return dp[row][col] = ans;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return -0;
        return solve(0,0,m,n,dp,obstacleGrid);
    }
};