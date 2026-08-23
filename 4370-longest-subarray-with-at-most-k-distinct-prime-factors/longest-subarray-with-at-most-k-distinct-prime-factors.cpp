class Solution {
public:
void solve(vector<vector<int>>& m,int idx,int val,map<int,int>& freq){
    for(int i=2;i*i<=val;i++){
        if(val%i == 0) {
            m[idx].push_back(i);
            freq[i]++;
        }
        while(val%i == 0){
            val/=i;
        }
    }
    if(val > 1) {
        m[idx].push_back(val);
        freq[val]++;
    }
}
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int maxi = 0;
        vector<vector<int>> m(n);
        map<int,int>freq;
        while(j < n){
            solve(m,j,nums[j],freq);
            if(freq.size() <= k)
            {
                maxi = max(maxi,j-i+1);
                j++;
            }
            else{
                while(freq.size() > k){
                    for(auto z : m[i]){
                        freq[z]--;
                        if(freq[z] == 0) freq.erase(z);
                    }
                    m[i].clear();
                    i++;
                }

                maxi = max(maxi,j-i+1);
                j++;
            }
        }
        return maxi;
    }
};