class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long x = 0;
        for(int i=1;i<n;i++){
            if(nums[i] + x >= nums[i-1] + x) continue;
            else{
                x+= nums[i-1] - nums[i];
            }
        }
        return x;
    }
};