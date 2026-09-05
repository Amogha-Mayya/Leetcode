class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mini(n,INT_MAX);
        vector<int>maxi(n,INT_MIN);
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        for(int i=n-1;i>=0;i--){
            min_ele=min(min_ele,nums[i]);
            mini[i] = min_ele;
        }
        for(int i=0;i<n;i++){
            max_ele=max(max_ele,nums[i]);
            maxi[i] = max_ele;
        }
        int score;
        for(int i=0;i<n;i++)
        {
            score = maxi[i] - mini[i];
            if(score <= k) return i;
        }
        return -1;
    }
};