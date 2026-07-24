class Solution {
public:
int atmost(vector<int>& nums,int k){
    if(k < 0) return 0;
    unordered_map<int,int>m;
    int i=0,j=0;
    int n = nums.size();
    int count = 0;
    while(j < n){
        m[nums[j]]++;
        if(m.size() < k){
            count += (j-i+1);
            j++;
        }
        else{
            while(m.size() > k){
                m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;
            }
            count += j-i+1;
            j++;
        }
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};