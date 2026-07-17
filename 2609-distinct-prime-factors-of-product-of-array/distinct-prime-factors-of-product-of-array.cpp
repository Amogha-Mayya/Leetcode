class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>s;
        for(auto num:nums){
            for(int i=2;i*i<=num;i++){
                if(num%i == 0){
                    s.insert(i);
                    while(num%i == 0){
                        num/=i;
                    }
                }
            }
            if(num > 1) s.insert(num);
        }
        return s.size();
    }
};