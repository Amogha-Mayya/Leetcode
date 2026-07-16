class Solution {
public:
long long solve(int mid,vector<int>& candies){
    long long k = 0;
    int n = candies.size();
    for(int i=0;i<n;i++){
        k+=(candies[i]/mid);
    }
    return k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(solve(mid,candies) >= k){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};