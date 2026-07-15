class Solution {
public:
int solve(vector<int>& nums,int low,int high){
    while(low<high){
        int mid = low + (high-low)/2;
        if(nums[mid] > nums[high])
            low = mid+1;
        else if(nums[mid] == nums[low] && nums[mid] == nums[high])
        {
            low++;
            high--;
        }
        else high = mid;
    }
    return low;
}
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return nums[solve(nums,low,high)];
    }
};