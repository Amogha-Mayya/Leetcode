class Solution {
public:
typedef pair<int,pair<int,int>> pp;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp>q;
        vector<vector<int>>v;
        for(auto i:points){
            int distance = (i[0] * i[0]) + (i[1]  * i[1]);
            q.push({distance,{i[0],i[1]}});
            if(q.size() > k)
                q.pop();
        }
        while(!q.empty()){
            v.push_back({q.top().second.first,q.top().second.second});
            q.pop();
        }
        return v;
    }
};