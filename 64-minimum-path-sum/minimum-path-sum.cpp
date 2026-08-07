class Solution {
public:
vector<vector<int>>c = {
    {0,1},{1,0}
};
int solve(int x,int y,int m,int n,vector<vector<int>>& dp,
vector<vector<int>>& grid){
    if(x == m-1 && y == n-1) return grid[x][y];
    if(dp[x][y] != -1) return dp[x][y];

    int down = INT_MAX;
    if(x+1 >=0 && x+1 < m){
        down = grid[x][y] + solve(x+1,y,m,n,dp,grid);
    }
    int right = INT_MAX;
    if(y+1 >=0 && y+1 < n){
        right = grid[x][y] + solve(x,y+1,m,n,dp,grid);
    }
    return dp[x][y] = min(down,right);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,dp,grid);
    }
};