class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[0][0] = 1;
        q.push({0,0});
        while(true){
            auto [x,y] = q.front();
            q.pop();
            char dir = grid[x][y];
            int xn = x, yn = y;
            if(dir == 'L') yn-=1;
            if(dir == 'R') yn+=1;
            if(dir == 'U') xn-=1;
            if(dir == 'D') xn+=1;
            if(xn>=0 && yn>=0 && xn<m && yn<n){
                if(!vis[xn][yn]){
                    vis[xn][yn] = 1;
                    q.push({xn,yn});
                }
                else{
                    return {x,y};
                }
            }
            else{
                return {x,y};
            }
        }
        return {};
    }
};