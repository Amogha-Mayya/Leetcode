class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n,0);
        for(auto i:queries){
            int l = i[0];
            int r = i[1];
            diff[l]+=1;
            if(r+1 < n)
            diff[r+1]-=1;
        }
        vector<int>v;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            v.push_back(sum);
        }
        for(int i=0;i<n;i++){
            if(v[i] - nums[i] < 0) return false;
        }
        return true;
    }
};