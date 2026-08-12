class Solution {
public:
int check(int mid,vector<int>& weights){
    int sum = 0;
    int n = weights.size();
    int days = 1;
    for(int i=0;i<n;i++){
        if(sum + weights[i] <= mid){
            sum += weights[i];
        }
        else{
            days++;
            sum = weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,weights) <= days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};