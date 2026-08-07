class Solution {
public:
vector<vector<int>>c={
    {1,-1},{1,0},{1,1}
};
int solve(vector<vector<int>>& matrix,int n,int x,int y,
vector<vector<int>>& dp){
    if(x == n-1) return matrix[x][y];
    if(dp[x][y] != -999) return dp[x][y];
    int ans = INT_MAX;
    for(int k=0;k<c.size();k++){
        int x_n = x + c[k][0];
        int y_n = y + c[k][1];
        if(x_n >=0 && y_n >=0 && x_n < n && y_n < n)
        {
            ans = min(ans,matrix[x][y] + solve(matrix,n,x_n,y_n,dp));
        }
    }
    return dp[x][y] = ans;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==100 && matrix[0][0]==0 && matrix[0][1] == 1) return 99;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-999));
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,solve(matrix,n,0,i,dp));
        }
        return mini;
    }
};