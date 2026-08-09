class Solution {
public:
int ncr(int row,int col){
    int ans = 1;
    for(int i=1;i<=col;i++){
        ans*=(row-i+1);
        ans/=i;
    }
    return ans;
}
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                int ans = ncr(i,j);
                temp.push_back(ans);
            }
            v.push_back(temp);
        }
        return v;
    }
};