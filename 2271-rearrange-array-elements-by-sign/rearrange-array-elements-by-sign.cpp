class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v,v2;
        for(auto i:nums){
            if(i >= 0) v.push_back(i);
            else v2.push_back(i);
        }
        int i=0,j=0;
        vector<int>ans;
        while(i < v.size() && j < v2.size()){
            ans.push_back(v[i++]);
            ans.push_back(v2[j++]);
        }
        return ans;
    }
};