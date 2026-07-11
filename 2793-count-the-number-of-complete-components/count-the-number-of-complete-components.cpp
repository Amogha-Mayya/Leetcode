class Solution {
public:
void dfs(int node,unordered_map<int,vector<int>>& m,vector<int>& vis,
vector<int>& temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto x:m[node]){
        if(!vis[x]){
            dfs(x,m,vis,temp);
        }
    }
}
bool check(unordered_map<int,vector<int>>& m,vector<int>& temp){
    int num_nodes = temp.size();
    for(auto i:temp){
        if(m[i].size() == num_nodes-1) continue;
        else return false;
    }
    return true;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            m[a].push_back(b);
            m[b].push_back(a);
        }
        vector<int>vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(i,m,vis,temp);
                if(check(m,temp))
                    count++;
            }
        }
        return count;
    }
};