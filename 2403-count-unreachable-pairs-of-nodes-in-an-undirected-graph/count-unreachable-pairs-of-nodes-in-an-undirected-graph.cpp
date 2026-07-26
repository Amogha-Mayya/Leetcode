class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x){
		if(x == parent[x]) return x;
		
		return parent[x] = find(parent[x]);
}
void Union(int x,int y){
		int x_parent = find(x);
		int y_parent = find(y);
		
		if(x_parent == y_parent) return;
		
		if(rank[x_parent] > rank[y_parent])
				parent[y_parent] = x_parent;
		else if(rank[x_parent] < rank[y_parent])
				parent[x_parent] = y_parent;
		else{
				parent[x_parent] = y_parent;
				rank[x_parent]++;
		}
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i] = i;
        int components = n;
        vector<int>v;
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            Union(u,v);
        }
        // component -> size of component
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int papaji = find(i);
            m[papaji]++;
        }
        // find result from map
        long long result = 0;
        long long remaining = n;
        for(auto it:m){
            long long size = it.second;
            result += (size) * (remaining - size);
            remaining -= size;
        }
        return result;
    }
};