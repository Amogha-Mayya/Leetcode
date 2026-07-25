class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1},
    {1,1},{-1,-1},{-1,1},{1,-1}
};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int x_src = 0;
        int y_src = 0;
        int x_tar = n-1;
        int y_tar = n-1;
        if(grid[x_src][y_src] == 1 ||
        grid[x_tar][y_tar] == 1) return -1;
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({x_src,y_src});
        vis[x_src][y_src] = 1;
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                if((x == x_tar) && (y == y_tar)) return count;
                for(int k=0;k<c.size();k++){
                    int xn = x + c[k][0];
                    int yn = y + c[k][1];
                    if(xn >=0 && yn >=0 && xn < n && yn < n
                    && grid[xn][yn] == 0 && !vis[xn][yn]){
                        q.push({xn,yn});
                        vis[xn][yn] = 1;
                    }
                } 
            }
            count++;
        }
        return -1;
    }
};