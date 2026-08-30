class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int maxi_idx = 0,mini_idx = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxi_idx = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                mini_idx = i;
            }
        }
        int count = INT_MAX;
        if(maxi_idx > mini_idx){
            count = min({maxi_idx + 1,n - mini_idx,n - maxi_idx + mini_idx + 1});
        }
        else{
            count = min({mini_idx + 1,n - maxi_idx,n - mini_idx + maxi_idx + 1});
        }
        return count;
    }
};