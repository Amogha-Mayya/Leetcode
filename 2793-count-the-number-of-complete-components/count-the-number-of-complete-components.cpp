class Solution {
public:
void dfs(int node,vector<int>& vis,unordered_map<int,vector<int>>& m,
vector<int>& temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto i:m[node]){
        if(!vis[i])
            dfs(i,vis,m,temp);
    }

}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        unordered_map<int,vector<int>>m;
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
            if(!vis[i]){
                dfs(i,vis,m,temp);
            }
            else continue;
            int num = temp.size();
            bool flag = true;
            for(auto i:temp){
                if(m[i].size() != (num-1))
                    flag = false;
            }
            if(flag == true) ans++;
        }
        return ans;
    }
};