class Solution {
public:
typedef pair<double,int>pp;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>m;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double c = succProb[i];
            m[a].push_back({b,c});
            m[b].push_back({a,c});
        }
        priority_queue<pp>q;
        vector<double>dist(n,0.0);
        dist[start_node] = 1.0;
        q.push({1.0,start_node});
        while(!q.empty()){
            auto [d,u] = q.top();
            q.pop();
            for(auto i:m[u]){
                int v = i.first;
                double wt = i.second;
                if(dist[u] * wt > dist[v]){
                    dist[v] = dist[u] * wt;
                    q.push({dist[v],v});
                }
            }
        }
        return dist[end_node];
    }
};