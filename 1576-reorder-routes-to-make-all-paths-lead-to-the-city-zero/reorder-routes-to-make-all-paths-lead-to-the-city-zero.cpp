class Solution {
public:
void dfs(int node,unordered_map<int,vector<int>>& mf,
unordered_map<int,vector<int>>& mb,int& count,vector<int>& vis){
    vis[node] = 1;
    for(auto i:mf[node]){
        if(!vis[i]){
            count++;
            dfs(i,mf,mb,count,vis);
        }
    }
    for(auto i:mb[node]){
        if(!vis[i])
            dfs(i,mf,mb,count,vis);
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>>mf;
        unordered_map<int,vector<int>>mb;
        for(auto i:connections){
            int a = i[0];
            int b = i[1];
            mf[a].push_back(b);
            mb[b].push_back(a);
        }
        vector<int>vis(n,0);
        int count = 0;
        dfs(0,mf,mb,count,vis);
        return count;
    }
};