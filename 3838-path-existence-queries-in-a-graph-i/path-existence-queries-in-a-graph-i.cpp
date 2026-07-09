class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>component(n);
        component[0] = 0;
        int id = 0;
        for(int i=1;i<n;i++){
            if(abs(nums[i] - nums[i-1]) > maxDiff)
            {
                id++;
            }
            component[i] = id;
        }
        vector<bool>v;
        for(auto i:queries){
            v.push_back(component[i[0]] == component[i[1]]);
        }
        return v;
    }
};