class Solution {
public:
typedef pair<int,int> pp;
struct cmp{
    bool operator()(pp a,pp b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums)
            m[i]++;
        priority_queue<pp,vector<pp>,cmp>q;
        for(auto it:m){
            int count = it.second;
            int num = it.first;
            q.push({count,num});
        }
        vector<int>v;
        while(!q.empty()){
            for(int i=0;i<q.top().first;i++)
                v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};