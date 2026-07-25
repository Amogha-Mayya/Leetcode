class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int k=0;k<c.size();k++){
                int xn = x + c[k][0];
                int yn = y + c[k][1];
                if(xn >=0 && yn >=0 && xn < m && yn < n
                && ans[xn][yn] == -1){
                    ans[xn][yn] = ans[x][y] + 1;
                    q.push({xn,yn});
                }
            }
        }
        return ans;
    }
};