class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>m;
            for(int j=i;j<n;j++){
                m[nums[j]]++;
                int len = j-i+1;
                if(m[target] > len/2)
                    count++;
            }
        }
        return count;
    }
};