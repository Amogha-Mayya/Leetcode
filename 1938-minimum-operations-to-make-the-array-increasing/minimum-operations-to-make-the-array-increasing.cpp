class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int sum = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > prev){
                prev = nums[i];
                continue;
            }
            else{
                sum += (prev - nums[i] + 1);
                prev = prev + 1;
            }
        }
        return sum;
    }
};