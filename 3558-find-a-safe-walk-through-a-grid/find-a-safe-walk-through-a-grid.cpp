class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // 01 BFS ( applied only when grid has either 0 or 1)
        // just find shortest path from source to all the nodes

        int m = grid.size();
        int n = grid[0].size();
        deque<pair<int,int>>dq;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        // result[i][j] = minimum cost from source to i,j 
        result[0][0] = grid[0][0];
        dq.push_front({0,0});
        while(!dq.empty()){
            auto [x,y] = dq.front();
            dq.pop_front();
            for(int k=0;k<c.size();k++){
                int xn = x + c[k][0];
                int yn = y + c[k][1];
                if(xn < 0 || yn < 0 || xn >= m || yn >= n) continue;
                if(result[x][y] + grid[xn][yn] <  result[xn][yn]){
                    result[xn][yn] = result[x][y] + grid[xn][yn];

                    // to keep in sorted order
                    if(grid[xn][yn] == 0)
                        dq.push_front({xn,yn});
                    else dq.push_back({xn,yn});
                }
            }
        }
        // minimum health required to reach destination
        int min_health = result[m-1][n-1];
        return (health - min_health >= 1);
    }
};