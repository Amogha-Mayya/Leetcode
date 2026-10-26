class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{0,-1},{-1,0}
};
typedef long long ll;
ll bfs(vector<vector<int>>& grid,int x,int y,int m,int n, vector<vector<int>>& vis){
    queue<pair<int,int>>q;
    q.push({x,y});
    ll sum = grid[x][y];
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int k=0;k<c.size();k++){
            int xn = x + c[k][0];
            int yn = y + c[k][1];
            if(xn>=0 && yn >=0 && xn < m && yn < n && grid[xn][yn] > 0 && !vis[xn][yn])
            {
                q.push({xn,yn});
                vis[xn][yn] = 1;
                sum+= grid[xn][yn];
            }
        }
    }
    return sum;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] > 0){
                    vis[i][j] = 1;
                    if((bfs(grid,i,j,m,n,vis) % k) == 0) ans++;
                }
            }
        }
        return ans;
    }
};