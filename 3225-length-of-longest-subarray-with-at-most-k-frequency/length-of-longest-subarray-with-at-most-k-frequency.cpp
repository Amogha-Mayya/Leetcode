class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        unordered_map<int,int>m;
        int maxi = 0;
        while(j < n){
            m[nums[j]]++;
            while(m[nums[j]] > k){
                m[nums[i]]--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};