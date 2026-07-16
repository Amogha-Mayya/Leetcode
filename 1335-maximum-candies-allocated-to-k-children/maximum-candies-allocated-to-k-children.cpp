class Solution {
public:
long long solve(vector<int>& nums,int mid){
    int n = nums.size();
    long long count = 0;
    for(int i=0;i<n;i++){
        count += (nums[i]/mid);
    }
    return count;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(solve(candies,mid) >= k){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};