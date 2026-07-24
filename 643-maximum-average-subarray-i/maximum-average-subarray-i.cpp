class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        double avg = 0, maxi = INT_MIN;
        int sum = 0;
        while(j < n){
            sum += nums[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                avg = (double)sum/k;
                maxi = max(maxi,avg);
                sum-=nums[i];
                i++;j++;
            }
        }
        return maxi;
    }
};