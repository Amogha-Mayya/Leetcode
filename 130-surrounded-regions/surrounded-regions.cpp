class Solution {
public:
vector<vector<int>>c = {
    {1,0},{0,1},{0,-1},{-1,0}
};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>>q;
        // push all the boundary O's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    if(board[i][j] == 'O')
                        q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int k=0;k<c.size();k++){
                int xn = x + c[k][0];
                int yn = y + c[k][1];
                if(xn>=0 && yn>=0 && xn<m && yn<n
                && board[xn][yn] == 'O'){
                    q.push({xn,yn});
                    board[xn][yn] = '#';
                }
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};