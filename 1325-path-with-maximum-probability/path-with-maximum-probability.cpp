class Solution {
public:
typedef pair<double,int>pp;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int x = 0;
        unordered_map<int,vector<pair<int,double>>>m;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            double c = succProb[x++];
            m[a].push_back({b,c});
            m[b].push_back({a,c});
        }
        vector<double>dist(n,0.0);
        dist[start_node] = 1.0;
        priority_queue<pp>q;
        q.push({1.0,start_node});
        while(!q.empty()){
            auto [d,u] = q.top();
            q.pop();
            for(auto i:m[u]){
                double wt = i.second;
                int v = i.first;
                if(wt * dist[u] > dist[v]){
                    q.push({dist[v],v});
                    dist[v] = dist[u] * wt;
                }
            }
        }
        return dist[end_node];
    }
};