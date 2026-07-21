class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n,0);
        for(auto i:queries){
            int left = i[0];
            int right = i[1];
            int val = -1;
            diff[left]-=val;
            if(right + 1 < n)
            diff[right + 1]+=val;
        }
        // take prefix sum
        vector<int>v;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += diff[i];
            v.push_back(sum);
        }
        for(int i=0;i<n;i++){
            if(v[i] - nums[i] < 0) return false;
        }
        return true;
    }
};