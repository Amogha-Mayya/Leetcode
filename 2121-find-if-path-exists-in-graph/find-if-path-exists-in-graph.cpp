class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>m;
        // adjacency list
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            m[a].push_back(b);
            m[b].push_back(a);
        }
        queue<int>q;
        q.push(source);
        vector<int>vis(n,0);
        vis[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination) return true;
            for(auto i:m[node]){
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return false;
    }
};