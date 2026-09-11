class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int temp = image[sr][sc];
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        q.push({sr,sc});
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int k=0;k<c.size();k++){
                int xn = x + c[k][0];
                int yn = y + c[k][1];
                if(xn>=0 && yn>=0 && xn<m && yn<n && !vis[xn][yn] && 
                image[xn][yn] == temp){
                    q.push({xn,yn});
                    vis[xn][yn] = 1;
                    image[xn][yn] = color;
                }
            }
        }
        return image;
    }
};