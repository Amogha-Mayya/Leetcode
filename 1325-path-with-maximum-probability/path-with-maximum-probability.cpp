class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>m;
        int k = 0;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            double c = succProb[k++];
            m[a].push_back({b,c});
            m[b].push_back({a,c});
        }
        vector<double>dist(n,0.0);
        dist[start_node] = 1.0;
        priority_queue<pair<double,int>>q;
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