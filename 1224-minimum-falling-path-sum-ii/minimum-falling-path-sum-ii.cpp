class Solution {
public:
int solve(int x,int y,vector<vector<int>>& matrix,int n,
vector<vector<int>>& dp){
    if(x == n-1) return matrix[x][y];
    if(dp[x][y] != INT_MIN) return dp[x][y];
    int ans = INT_MAX;
    for(int k=-n+1;k<n;k++){
        int xn = x + 1;
        int yn = y + k;
        if(xn >=0 && yn >=0 && xn < n && yn < n && y!=yn){
            ans = min(ans,matrix[x][y] + solve(xn,yn,matrix,n,dp));
        }
    }
    return dp[x][y] = ans;
}
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,solve(0,i,grid,n,dp));
        }
        return ans;
    }
};