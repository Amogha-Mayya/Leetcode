class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxi(n,0);
        vector<int>mini(n,1e9);
        int maxi2=0,mini2=1e9;
        for(int i=0;i<n;i++){
            maxi2 = max(maxi2,nums[i]);
            maxi[i] = maxi2;
        }
        for(int i=n-1;i>=0;i--){
            mini2 = min(mini2,nums[i]);
            mini[i] = mini2;
        }
        for(int i=0;i<n;i++){
            if(abs(maxi[i] - mini[i]) <= k) return i;
        }
        return -1;
    }
};