class Solution {
public:
int solve(vector<vector<int>>& matrix,int n,int x,int y,
vector<vector<int>>& dp){
    if(x == n-1) return matrix[x][y];
    if(dp[x][y] != -999) return dp[x][y];
    int ans = INT_MAX;
    for(int col = 0; col < n; col++){
        if(col == y) continue;
        ans = min(ans,
                matrix[x][y] + solve(matrix, n, x + 1, col, dp));
    }
    return dp[x][y] = ans;
}
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-999));
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,solve(grid,n,0,i,dp));
        }
        return mini;
    }
};