class Solution {
public:
vector<vector<int>>c = {
    {1,0},{1,1},{1,-1}
};
int solve(int x,int y,vector<vector<int>>& matrix,int n,
vector<vector<int>>& dp){
    if(x == n-1) return matrix[x][y];
    if(dp[x][y] != INT_MIN) return dp[x][y];
    int ans = INT_MAX;
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >=0 && yn >=0 && xn < n && yn < n){
            ans = min(ans,matrix[x][y] + solve(xn,yn,matrix,n,dp));
        }
    }
    return dp[x][y] = ans;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,solve(0,i,matrix,n,dp));
        }
        return ans;
    }
};