class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int count = 0;
        int maxi = 0;
        while(j < n){
            if(nums[j] == 0)
                count++;
            if(count <= k){
                maxi = max(maxi,j-i+1);
                j++;
            }
            else{
                while(count > k){
                    if(nums[i] == 0) count--;
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};