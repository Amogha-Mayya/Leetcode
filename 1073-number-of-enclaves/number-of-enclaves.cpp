class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int k=0;k<c.size();k++){
                int xn = x + c[k][0];
                int yn = y + c[k][1];
                if(xn > 0 && yn > 0 && xn < m-1 && yn < n-1
                && grid[xn][yn] == 1){
                    grid[xn][yn] = 0;
                    q.push({xn,yn});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i > 0 && j > 0 && i < m-1 && j < n-1 &&
                grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};