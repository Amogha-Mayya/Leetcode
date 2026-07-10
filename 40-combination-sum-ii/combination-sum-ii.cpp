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
    if(target == 0){
        v.push_back(temp);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if(i > idx && nums[i] == nums[i-1]) continue;
        if(nums[i] > target) break;
        temp.push_back(nums[i]);
        solve(i + 1, nums, v,temp,target - nums[i]);
        temp.pop_back(); 
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>v;
        vector<int>temp;
        solve(0,candidates,v,temp,target);
        return v;
    }
};