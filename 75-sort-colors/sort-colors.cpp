class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count1 = 0,count2 = 0,count3 = 0;
        for(auto i:nums){
            if(i == 0) count1++;
            else if(i == 1) count2++;
            else count3++;
        }
        nums.clear();
        while(count1--) nums.push_back(0);
        while(count2--) nums.push_back(1);
        while(count3--) nums.push_back(2);
    }
};