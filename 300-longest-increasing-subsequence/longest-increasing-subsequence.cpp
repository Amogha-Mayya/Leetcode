class Solution {
public:
int solve(int idx,vector<int>& nums,int prev,
vector<vector<int>>& dp){
    if(idx == nums.size()){
        return 0;
    }
    // pick the element
    if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
    int pick = 0;
    if(prev == -1 || nums[prev] < nums[idx])
    pick = 1 + solve(idx+1,nums,idx,dp);
    // not pick the element
    int notpick = solve(idx+1,nums,prev,dp);
    return dp[idx][prev+1] = max(pick,notpick);
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int prev = -1;
        return solve(idx,nums,prev,dp);
    }
};