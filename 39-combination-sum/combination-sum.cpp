class Solution {
public:
void solve(int idx,vector<int>& nums,vector<vector<int>>& v,
vector<int>& temp,int target){
    if(idx == nums.size()){
        if(target == 0)
            v.push_back(temp);
        return;
    }
    if(target < 0) return;
    temp.push_back(nums[idx]);
    solve(idx,nums,v,temp,target - nums[idx]);
    temp.pop_back();
    solve(idx+1,nums,v,temp,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>temp;
        solve(0,candidates,v,temp,target);
        return v;
    }
};