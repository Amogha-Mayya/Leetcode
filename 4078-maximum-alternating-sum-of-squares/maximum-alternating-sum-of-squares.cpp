class Solution {
public:
typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        for(auto i:nums)
            v.push_back(abs(i));
        sort(v.begin(),v.end(),greater<int>());
        ll sum = 0;
        if(n % 2 == 0){
            for(int i=0;i<n/2;i++){
                sum = sum + (v[i] * v[i]);
            }
            for(int i=n/2;i<n;i++){
                sum = sum - (v[i] * v[i]);
            }
        }
        else{
            for(int i=0;i<=n/2;i++){
                sum = sum + (v[i] * v[i]);
            }
            for(int i=n/2 + 1;i<n;i++){
                sum = sum - (v[i] * v[i]);
            }
        }
        return sum;
    }
};