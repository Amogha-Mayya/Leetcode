class Solution {
public:
bool solve(int node,unordered_map<int,vector<int>>& m,
vector<int>& vis,vector<int>& color,int clr){
    vis[node] = 1;
    color[node] = clr;
    for(auto i:m[node]){
        if(!vis[i]){
            if(solve(i,m,vis,color,!clr) == false) return false;
        }
        else{
            if(color[i] == clr) return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        // adjacency list
        int n = graph.size();
        unordered_map<int,vector<int>>m;
        int k = 0;
        for(auto i:graph){
            for(auto j:i){
                m[k].push_back(j);
            }
            k++;
        }
        vector<int>vis(n,0);
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i])
            if(solve(i,m,vis,color,0) == false) return false;
        }
        return true;
    }
};