class Solution {
public:
bool check(vector<vector<int>>& grid,int row,int col,int n){
    // right check 
    for(int i=col+1;i<n;i++)
        if(grid[row][i] == 1) return false;
    // left check 
    for(int i=col-1;i>=0;i--)
        if(grid[row][i] == 1) return false;
    // top check
    for(int i=row-1;i>=0;i--)
        if(grid[i][col] == 1) return false;
    // bottom check
    for(int i=row+1;i<n;i++)
        if(grid[i][col] == 1) return false;
    // up left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        if(grid[i][j] == 1) return false;
    // down right diagonal
    for(int i=row+1,j=col+1;i<n && j<n;i++,j++)
        if(grid[i][j] == 1) return false;
    // down left diagonal
    for(int i=row+1,j=col-1;i<n && j>=0;i++,j--)
        if(grid[i][j] == 1) return false;
    // up right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        if(grid[i][j] == 1) return false;
    return true;
}
void solve(int row,vector<vector<int>>& grid,
vector<vector<string>>& v,vector<string>& temp,int n){
    if(row == n){
        v.push_back(temp);
        return;
    }
    for(int col=0;col<n;col++){
        if(check(grid,row,col,n)){
            grid[row][col] = 1;
            temp[row][col] = 'Q';
            solve(row+1,grid,v,temp,n);
            temp[row][col] = '.';
            grid[row][col] = 0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>grid(n,vector<int>(n,0));
        vector<vector<string>>v;
        vector<string>temp;
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=0;j<n;j++)
                str+='.';
            temp.push_back(str);
        }
        solve(0,grid,v,temp,n);
        return v;
    }
};