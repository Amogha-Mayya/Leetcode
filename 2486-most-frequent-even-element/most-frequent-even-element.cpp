class Solution {
public:
typedef pair<int,int>pp;
static bool cmp(pp a, pp b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v;
        unordered_map<int,int>m;
        for(auto i:nums){
            if(i % 2 == 0)
                m[i]++;
        }
        if(m.size() == 0) return -1;
        for(auto it:m){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        return v[0].first;
    }
};