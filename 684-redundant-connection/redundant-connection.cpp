class Solution {
public:
vector<int>rank;
vector<int>parent;
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void Union(int a,int b){
    int parent_a = find(a);
    int parent_b = find(b);
    if(parent_a == parent_b) return;
    if(rank[parent_a] > rank[parent_b])
        parent[parent_b] = parent_a;
    else if(rank[parent_a] < rank[parent_b])
        parent[parent_a] = parent_b;
    else{
        parent[parent_a] = parent_b;
        rank[parent_a]++;
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
            parent[i] = i;
        vector<int>ans;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            if(find(a) == find(b)){
                ans.push_back(a);
                ans.push_back(b);
            }
            else{
                Union(a,b);
            }
        }
        return ans;
    }
};