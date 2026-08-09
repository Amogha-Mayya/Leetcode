class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        vector<int>v;
        for(auto it:m){
            int temp = it.first;
            int count = it.second;
            if(count > n/3) v.push_back(temp);
        }
        return v;
    }
};