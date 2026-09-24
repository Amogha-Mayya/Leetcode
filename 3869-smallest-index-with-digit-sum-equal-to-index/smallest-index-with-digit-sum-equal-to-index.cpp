class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int k = 0;
        for(auto i: nums){
            int temp = i;
            int sum = 0;
            while(temp){
                sum += (temp%10);
                temp/=10;
            }
            if(sum == k) return k;
            k++;
        }
        return -1;
    }
};