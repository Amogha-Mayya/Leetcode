class Solution {
public:
int check(int mid,vector<int>& nums){
    int n = nums.size();
    int rob = 0;
    for(int i=0;i<n;){
        if(nums[i] <= mid){
            rob++;
            i+=2;
        }
        else i++;
    }
    return rob;
}
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid,nums) >= k){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};