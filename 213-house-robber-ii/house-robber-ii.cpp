class Solution {
public:
int solve(int idx,int n,vector<int>& nums,
vector<int>& dp){
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];
    int pick = nums[idx] + solve(idx + 2,n,nums,dp);
    int notpick = solve(idx + 1,n,nums,dp);
    return dp[idx] = max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        vector<int>dp(n + 1,-1);
        vector<int>dp2(n + 1,-1);
        return max(solve(0,n-1,nums,dp),solve(1,n,nums,dp2));
    }
};