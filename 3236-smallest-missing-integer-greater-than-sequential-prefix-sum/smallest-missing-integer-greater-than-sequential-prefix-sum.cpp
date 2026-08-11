class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int maxi_sum = nums[0];
        int sum = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == (nums[i-1] + 1)){
                sum += nums[i];
                maxi_sum = max(maxi_sum,sum);
            }
            else break;
        }
        for(int i=maxi_sum;i<=1e6;i++){
            if(find(nums.begin(),nums.end(),i) == nums.end())
                return i;
        }
        return -1;
    }
};