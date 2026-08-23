class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int>st;
        for(int i=lower;i<=upper;i++)
            st.insert(i);
        for(auto i:nums)
            st.erase(i);
        vector<vector<int>>v;
        for(int i:st)
            v.push_back({i,i});
        vector<vector<int>>ans;
        for(auto i:v){
            if(ans.empty() || ans.back()[1] < i[0]-1){
                ans.push_back(i);
            }
            else{
                ans.back()[1] = max(ans.back()[1],i[1]);
            }
        }
        return ans;
    }
};