class Solution {
public:
typedef pair<int,int>pp;
void dijkstra(int node,vector<int>& dist,
unordered_map<int,vector<pp>>& m){
    priority_queue<pp,vector<pp>,greater<pp>>q;
    q.push({0,node});
    dist[node] = 0;
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
        unordered_map<int,vector<pp>>m;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            int c = i[2];
            m[a].push_back({b,c});
            m[b].push_back({a,c});
        }
        int ans = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            vector<int>dist(n,1e9);
            int count = 0;
            dijkstra(i,dist,m);
            for(auto j:dist){
                if(j <= distanceThreshold) count++;
            }
            if(count <= mini){
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
};