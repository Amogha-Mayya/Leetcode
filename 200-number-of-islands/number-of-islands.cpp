class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
void dfs(int x,int y,vector<vector<char>>& grid,
vector<vector<int>>& vis,int m,int n){
    vis[x][y] = 1;
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n && !vis[xn][yn] && 
        grid[xn][yn] == '1'){
            dfs(xn,yn,grid,vis,m,n);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    dfs(i,j,grid,vis,m,n);
                }
            }
        }
        return count;
    }
};