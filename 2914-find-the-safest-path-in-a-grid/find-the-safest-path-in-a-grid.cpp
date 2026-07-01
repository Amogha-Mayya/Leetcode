class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
bool check(vector<vector<int>>&dist, int sf,int n){
    // apply bfs to check if there exists such path
    queue<pair<int,int>>q;
    vector<vector<int>>vis(n,vector<int>(n,0));
    // (0,0) -> (n-1,n-1)
    if(dist[0][0] < sf || dist[n-1][n-1] < sf)
        return false;
    q.push({0,0});
    vis[0][0] = 1;
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();
        if(i == n-1 && j == n-1) return true;

        for(int k=0;k<c.size();k++){
            int ni = i + c[k][0];
            int nj = j + c[k][1];
            if(ni>=0 && nj>=0 && ni < n && nj < n && !vis[ni][nj]){
                if(dist[ni][nj] < sf){
                    continue;
                    // reject this cell 
                }
                q.push({ni,nj});
                vis[ni][nj] = 1;
            }
        }
    }
    return false;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        // pre-calculation of distance to nearest thief - for each cell
        vector<vector<int>> dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // push to queue if it is a thief
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                dist[x][y] = level;
                for(int k=0;k<c.size();k++){
                    int xn = x + c[k][0];
                    int yn = y + c[k][1];
                    if(xn >=0 && yn >=0 && xn < n && yn < n && !vis[xn][yn]){
                        q.push({xn,yn});
                        vis[xn][yn] = 1;
                    }
                }
            }
            level++;
        }

        // apply binary search on safeness factor
        int l = 0;
        int r = 2 * (n - 1);
        int result = 0;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(check(dist,mid,n))
            {
                result = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return result;
    }
};