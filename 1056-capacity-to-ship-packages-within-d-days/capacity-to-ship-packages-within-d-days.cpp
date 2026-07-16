class Solution {
public:
int solve(int mid,vector<int>& weights){
    int n = weights.size();
    int days = 1;
    long long sum = 0;
    for(int i=0;i<n;i++){
        if(sum + weights[i] <= mid){
            sum += weights[i];
        }
        else{
            sum = weights[i];
            days++;
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(solve(mid,weights) <= days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};