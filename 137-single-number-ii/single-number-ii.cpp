class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        for(int bit=0;bit<=31;bit++){
            int count = 0;
            for(auto i:nums){
                if(i&(1<<bit)) count++;
            }
            if(count%3 != 0)
                temp = temp|(1<<bit);
        }
        return temp;
    }
};