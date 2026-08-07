class Solution {
public:
int solve(int x,int y,vector<vector<int>>& triangle,int m,int n,
vector<vector<int>>& dp){
    if(x == m-1) return triangle[x][y];
    int pick1 = INT_MAX , pick2 = INT_MAX;
    if(dp[x][y] != INT_MIN) return dp[x][y];
    pick1 = triangle[x][y] + solve(x+1,y,triangle,m,n,dp);
    pick2 = triangle[x][y] + solve(x+1,y+1,triangle,m,n,dp);
    return dp[x][y] = min(pick1,pick2);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        return solve(0,0,triangle,m,m,dp);
    }
};