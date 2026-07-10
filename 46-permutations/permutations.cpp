class Solution {
public:
void solve(int idx,vector<int>& nums,
vector<vector<int>>& v,vector<int>& temp){
    if(idx == nums.size()){
        v.push_back(temp);
        return;
    }
    for(int k=idx;k<nums.size();k++){
        swap(temp[idx],temp[k]);
        solve(idx+1,nums,v,temp);
        swap(temp[idx],temp[k]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>v;
        vector<int>temp = nums;
        solve(0,nums,v,temp);
        return v;
    }
};