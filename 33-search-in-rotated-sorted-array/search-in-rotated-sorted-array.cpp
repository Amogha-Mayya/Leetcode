class Solution {
public:
int solve(vector<int>& nums,int low,int high){
    while(low < high){
        int mid = low + (high-low)/2;
        if(nums[mid] > nums[high]){
            low = mid+1;
        }
        else high = mid;
    }
    return low;
}
int bs(vector<int>& nums,int low,int high,int target){
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target)
            low = mid+1;
        else high = mid-1;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int pivot = solve(nums,low,high);
        cout<<pivot<<endl;
        if(target >= nums[pivot] && target <= nums[high])
            return bs(nums,pivot,high,target);
        else return bs(nums,low,pivot-1,target);
    }
};