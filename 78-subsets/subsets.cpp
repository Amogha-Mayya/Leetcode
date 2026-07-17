class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        int n = nums.size();
        for(int i=0;i<pow(2,n);i++){
            vector<int>temp;
            int x = 0;
            int copy = i;
            while(copy>0){
                if(copy&1) temp.push_back(nums[x]);
                copy = (copy>>1);
                x++;
            }
            v.push_back(temp);
        }
        return v;
    }
};