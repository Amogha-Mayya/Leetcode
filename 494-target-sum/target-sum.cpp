class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum + target)%2 != 0) return 0;
        if(abs(target) > sum) return 0;
        int temp = (sum + target)/2;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(temp+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=temp;j++){
                int pick = 0;
                if(nums[i-1] <= j){
                    pick = dp[i-1][j - nums[i-1]];
                }
                int notpick = dp[i-1][j];
                dp[i][j] = (pick + notpick);
            }
        }
        return dp[n][temp];
    }
};