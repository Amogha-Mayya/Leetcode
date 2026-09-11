class Solution {
public:
void dfs(int node,unordered_map<int,vector<int>>& m,vector<int>& vis,
vector<int>& temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto i:m[node]){
        if(!vis[i])
            dfs(i,m,vis,temp);
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;
        // adjacency list
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            m[a].push_back(b);
            m[b].push_back(a);
        }
        vector<int>vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int>temp;
            bool flag = true;
            if(!vis[i]){
                dfs(i,m,vis,temp);
                for(auto i:temp){
                if(m[i].size() != temp.size()-1){
                    flag = false;
                    break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};