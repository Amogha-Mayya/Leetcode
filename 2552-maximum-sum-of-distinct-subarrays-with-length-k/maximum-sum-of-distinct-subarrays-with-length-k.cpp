class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0;
        int i=0,j=0;
        int n = nums.size();
        unordered_map<int,int>m;
        long long sum = 0;
        while(j < n){
            m[nums[j]]++;
            sum += nums[j];
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                if(m.size() == k){
                    maxi = max(maxi,sum);
                }
                sum-=nums[i];
                m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;j++;
            }
        }
        return maxi;
    }
};