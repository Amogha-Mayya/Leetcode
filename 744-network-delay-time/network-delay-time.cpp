class Solution {
public:
typedef pair<int,int> pp;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:times){
            int a = i[0];
            int b = i[1];
            int c = i[2];
            m[a].push_back({b,c});
        }
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        priority_queue<pp,vector<pp>,greater<pp>>q;
        q.push({0,k});
        while(!q.empty()){
            auto [d,u] = q.top();
            q.pop();
            if(d > dist[u]) continue;
            for(auto i:m[u]){
                int v = i.first;
                int wt = i.second;
                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    q.push({dist[v],v});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9) return -1;
            else maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};