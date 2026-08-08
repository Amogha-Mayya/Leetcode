class Solution {
public:
int solve(int row,int col,vector<vector<int>>& triangle,
vector<vector<int>>& dp){
    if(row == triangle.size()-1){
        return triangle[row][col];
    }
    if(dp[row][col] != INT_MIN) return dp[row][col];
    int pick1 = INT_MAX,pick2 = INT_MAX;
    pick1 = triangle[row][col] + solve(row+1,col,triangle,dp);
    pick2 = triangle[row][col] + solve(row+1,col+1,triangle,dp);
    return dp[row][col] = min(pick1,pick2);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        return solve(0,0,triangle,dp);
    }
};