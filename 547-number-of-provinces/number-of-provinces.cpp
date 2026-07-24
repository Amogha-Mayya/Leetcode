class Solution {
public:
void dfs(int node,vector<int>& vis,unordered_map<int,vector<int>>& m){
    vis[node] = 1;
    for(auto i:m[node]){
        if(!vis[i])
            dfs(i,vis,m);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        // adjacency matrix
        unordered_map<int,vector<int>>m;
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j] == 1){
                    m[i+1].push_back(j+1);
                }
            }
        }
        int count = 0;
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,m);
            }
        }
        return count;
    }
};