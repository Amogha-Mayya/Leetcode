class Solution {
public:
vector<vector<int>>c= {
    {1,0},{0,1},{-1,0},{0,-1}
};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int time = 0;
        while(!q.empty() && fresh){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                for(int k=0;k<c.size();k++){
                    int xn = x + c[k][0];
                    int yn = y + c[k][1];
                    if(xn >=0 && yn >=0 && xn < m
                    && yn < n && grid[xn][yn] == 1){
                        grid[xn][yn] = 2;
                        q.push({xn,yn});
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh > 0) return -1;
        else return time;
    }
};