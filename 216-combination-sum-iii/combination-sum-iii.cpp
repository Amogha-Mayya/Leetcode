class Solution {
public:
void solve(int idx,vector<vector<int>>& v,vector<int>& temp,
vector<int>& nums,int k,int n){
    if(temp.size() == k){
        if(n == 0){
            v.push_back(temp);
            return;
        }
    }
    if(idx == nums.size()) return;
    if(n < 0) return;
    if(temp.size() > k) return;
    temp.push_back(nums[idx]);
    solve(idx+1,v,temp,nums,k,n-nums[idx]);
    temp.pop_back();
    solve(idx+1,v,temp,nums,k,n);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>v;
        vector<int>temp;
        vector<int>nums;
        for(int i=1;i<=9;i++)
            nums.push_back(i);
        solve(0,v,temp,nums,k,n);
        return v;
    }
};