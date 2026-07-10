class Solution {
public:
int solve(int idx,vector<int>& nums,int prev_idx,
vector<vector<int>>& dp){
    if(idx >= nums.size()){
        return 0;
    }
    if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];
    int pick = 0;
    if((prev_idx == -1) || nums[idx] > nums[prev_idx])
    pick = 1 + solve(idx+1,nums,idx,dp);
    int notpick = solve(idx+1,nums,prev_idx,dp);
    return dp[idx][prev_idx + 1] = max(pick,notpick);
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};