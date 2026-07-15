class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ub = upper_bound(nums.begin(),nums.end(),target);
        auto lb = lower_bound(nums.begin(),nums.end(),target);

        if(lb == nums.end() || *lb != target)
            return {-1,-1};
        int lbv = lb - nums.begin();
        int ubv = ub - nums.begin();
        return {lbv,ubv-1};
    }
};