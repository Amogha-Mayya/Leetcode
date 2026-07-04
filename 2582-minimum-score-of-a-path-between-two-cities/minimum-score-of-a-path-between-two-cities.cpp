class Solution {
public:
int mini = INT_MAX;
void dfs(int node,unordered_map<int,vector<vector<int>>>&m,vector<int>& vis){
    vis[node] = 1;
    for(auto nbr:m[node]){
        int x = nbr[0];
        int c = nbr[1];
        mini = min(mini,c);
        if(!vis[x]){
            dfs(x,m,vis);
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<vector<int>>>m;
        for(auto i:roads){
            int a = i[0];
            int b = i[1];
            int c = i[2];
            m[a].push_back({b,c});
            m[b].push_back({a,c});
        }
        vector<int>vis(n+1,0);
        dfs(1,m,vis);
        return mini;
    }
};