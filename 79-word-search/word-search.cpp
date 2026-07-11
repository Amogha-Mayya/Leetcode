class Solution {
public:
vector<vector<int>> c = {
    {1,0},{0,1},{-1,0},{0,-1}
};
bool solve(int idx,int x,int y,vector<vector<char>>& board,
vector<vector<int>>& vis,string word,int m,int n){
    // base case here
    if(idx == word.size()){
        return true;
    }
    for(int k=0;k<c.size();k++){
        int xn = x + c[k][0];
        int yn = y + c[k][1];
        if(xn >= 0 && yn >=0 && xn < m && yn < n
        && !vis[xn][yn] && board[xn][yn] == word[idx]){
            vis[xn][yn] = 1;
            if(solve(idx+1,xn,yn,board,vis,word,m,n)) return true;
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
                    if(solve(1,i,j,board,vis,word,m,n)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};