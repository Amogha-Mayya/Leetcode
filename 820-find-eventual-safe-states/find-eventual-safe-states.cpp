class Solution {
public:
bool dfs(int node,vector<int>& vis,vector<int>& path,
vector<vector<int>>& graph){
    vis[node] = 1;
    path[node] = 1;
    for(auto i:graph[node]){
        if(!vis[i]){
            if(dfs(i,vis,path,graph)) return true;
        }
        else if(path[i]) return true;
    }
    path[node] = 0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // adjacency list already given
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,path,graph);
            }
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            if(path[i] == 0)
                v.push_back(i);
        }
        return v;
    }
};