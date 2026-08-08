class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
int solve(vector<vector<int>>& grid,int m,int n,int x,int y,int xt,int yt,
vector<vector<int>>& vis,int cnt,int total){
    if(x == xt && y == yt){
        return (cnt == total);
    }
    int ans = 0;
    for(int k=0;k<c.size();k++){
        int x_n = x + c[k][0];
        int y_n = y + c[k][1];
    if(x_n >=0 && y_n >=0 && x_n < m && y_n < n && (grid[x_n][y_n] == 0 || grid[x_n][y_n] == 2) &&
    vis[x_n][y_n] == 0){
            vis[x_n][y_n] = 1;
            ans += solve(grid,m,n,x_n,y_n,xt,yt,vis,cnt+1,total);
            vis[x_n][y_n] = 0;
        }
    }
    return ans;
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int x_src,y_src,x_tar,y_tar;
        int empty = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                    x_src = i,y_src = j;
                if(grid[i][j] == 2)
                    x_tar = i,y_tar = j;
                if(grid[i][j] != -1) empty++;
            }
        }
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[x_src][y_src] = 1;
        return solve(grid,m,n,x_src,y_src,x_tar,y_tar,vis,1,empty);
    }
};