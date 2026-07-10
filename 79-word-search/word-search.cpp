class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
bool solve(int x,int y,vector<vector<char>>& board, string word,int idx,int m,int n,vector<vector<int>>& vis){
    if(idx == word.size()){
        return true;
    }
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >=0 && yn >=0 && xn < m && yn < n && !vis[xn][yn]
        && (board[xn][yn] == word[idx])){
            vis[xn][yn] = 1;
            if(solve(xn,yn,board,word,idx+1,m,n,vis)) return true;
            vis[xn][yn] = 0;
        }
    }
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(solve(i,j,board,word,1,m,n,vis)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};