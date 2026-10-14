class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            int diff = nums[i] - nums[i-1];
            if(diff > 0){
                continue;
            }
            else{
                int add = abs(diff) + 1;
                nums[i] += add;
                ans += add;
            }
        }
        return ans;
    }
};