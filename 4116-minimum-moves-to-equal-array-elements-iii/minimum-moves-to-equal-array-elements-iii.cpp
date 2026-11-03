class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto it = max_element(nums.begin(),nums.end());
        int maxi = *it;
        int n = nums.size();
        int ans = 0;
        for(auto i:nums)
            ans += (maxi - i);
        return ans;
    }
};