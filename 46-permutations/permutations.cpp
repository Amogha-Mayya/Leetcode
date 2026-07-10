class Solution {
public:
void solve(int idx,vector<vector<int>>& v,vector<int>& nums,
vector<int>& temp){
    if(idx == nums.size()){
        v.push_back(temp);
        return;
    }
    for(int j=idx;j<nums.size();j++){
        swap(temp[j],temp[idx]);
        solve(idx+1,v,nums,temp);
        swap(temp[j],temp[idx]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp = nums;
        solve(0,v,nums,temp);
        return v;
    }
};