class Solution {
public:
typedef pair<int,int>pp;
void djikstra(int src,vector<int>& dist,unordered_map<int,vector<pair<int,int>>>& m,int n){
    priority_queue<pp,vector<pp>,greater<pp>>q;
    q.push({0,src});
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
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>m;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            int c = i[2];
            m[a].push_back({b,c});
            m[b].push_back({a,c});
        }
        int mini = INT_MAX, ans = 0;
        for(int i=0;i<n;i++){
            vector<int>dist(n,1e9);
            dist[i] = 0;
            djikstra(i,dist,m,n);
            int count = 0;
            for(int j=0;j<dist.size();j++){
                if(dist[j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= mini){
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
};