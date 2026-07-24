class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
void dfs(int x,int y,vector<vector<int>>& grid,
vector<vector<int>>& vis,int m,int n,int& sum){
    vis[x][y] = 1;
    sum += grid[x][y];
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n && !vis[xn][yn] && 
        grid[xn][yn] > 0){
            dfs(xn,yn,grid,vis,m,n,sum);
        }
    }
}
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int maxi = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    int sum = 0;
                    dfs(i,j,grid,vis,m,n,sum);
                    maxi = max(maxi,sum);
                }
            }
        }
        return maxi;
    }
};