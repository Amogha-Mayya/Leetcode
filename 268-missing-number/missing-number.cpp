class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i=0;i<nums.size() + 1;i++)
            xorr^=i;
        for(int i=0;i<nums.size();i++)
            xorr^=nums[i];
        return xorr;
    }
};