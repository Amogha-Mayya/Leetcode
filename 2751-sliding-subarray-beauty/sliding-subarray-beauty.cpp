class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int>m;
        int i=0,j=0;
        int n = nums.size();
        vector<int>v;
        while(j < n){
            if(nums[j] < 0)
                m[nums[j]]++;
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                int temp = x;
                for(auto &i:m){
                    temp-=i.second;
                    if(temp <= 0){
                        v.push_back(i.first);
                        break;
                    }
                }
                if(temp > 0) v.push_back(0);
                if(m.find(nums[i])!=m.end())
                    m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;
                j++;
            }
        }
        return v;
    }
};