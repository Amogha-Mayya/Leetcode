class Solution {
public:
int atmost(vector<int>& nums,int k){
    if(k < 0) return 0;
    int i=0,j=0;
    int n = nums.size();
    int sum = 0;
    int count = 0;
    while(j < n){
        sum += nums[j];
        if(sum <= k){
            count += (j-i+1);
            j++;
        }
        else{
            while(sum > k){
                sum -= nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atmost(nums,goal) - atmost(nums,goal-1);
    }
};