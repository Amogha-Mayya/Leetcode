class Solution {
public:
void solve(int idx,vector<int>& nums,vector<vector<int>>& v,
vector<int>& temp){
    if(idx == nums.size())
    {
        v.push_back(temp);
        return;
    }
    // pick
    temp.push_back(nums[idx]);
    solve(idx+1,nums,v,temp);
    temp.pop_back();
    // not pick
    solve(idx+1,nums,v,temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        solve(0,nums,v,temp);
        return v;
    }
};