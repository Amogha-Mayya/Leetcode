class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>>grid(m,vector<char>(n,'#'));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(j == 0) grid[i][j] = '.';
                if(i == m-1) grid[i][j] = '.';
            }
        }
        vector<string>v;
        for(auto i:grid)
        {
            string temp = "";
            for(auto j:i)
                temp+=j;
            v.push_back(temp);
        }
        return v;
    }
};