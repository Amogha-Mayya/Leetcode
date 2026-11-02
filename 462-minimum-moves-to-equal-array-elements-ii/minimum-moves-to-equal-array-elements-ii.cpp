class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int med = 0;
        if(n%2) med = nums[n/2];
        else med = (nums[n/2-1] + nums[n/2])/2;
        int ans = 0;
        for(auto i:nums)
            ans+= abs(i - med);
        return ans;
    }
};