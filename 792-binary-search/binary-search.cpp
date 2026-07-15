class Solution {
public:
int solve(vector<int>& nums,int target,int low,int high){
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target)
            high = mid-1;
        else low = mid+1;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        return solve(nums,target,low,high);
    }
};