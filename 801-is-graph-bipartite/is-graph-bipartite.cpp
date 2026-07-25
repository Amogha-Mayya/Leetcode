class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<int>& color,
int node,int clr){
    color[node] = clr;
    for(auto i:graph[node]){
        if(color[i] == -1){
            if(dfs(graph,color,i,!clr) == false) return false;
        }
        else if(color[i] == clr) return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(graph,color,i,0) == false) return false;
            }
        }
        return true;
    }
};