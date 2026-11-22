class Solution {
public:
int solve(int x,int y,vector<vector<int>>& triangle,
vector<vector<int>>& dp){
    if(x == triangle.size()-1) return triangle[x][y];
    if(dp[x][y] != -99) return dp[x][y];
    int pick1 = triangle[x][y] + solve(x+1,y,triangle,dp);
    int pick2 = triangle[x][y] + solve(x+1,y+1,triangle,dp);
    return dp[x][y] = min(pick1,pick2);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-99));
        return solve(0,0,triangle,dp);
    }
};