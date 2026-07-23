class Solution {
public:
typedef pair<int,int>pp;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto i:nums)
            m[i]++;
        priority_queue<pp,vector<pp>,greater<pp>>q;
        for(auto it:m){
            int count = it.second;
            int num = it.first;
            q.push({count,num});
            if(q.size() > k)
                q.pop();
        }
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};