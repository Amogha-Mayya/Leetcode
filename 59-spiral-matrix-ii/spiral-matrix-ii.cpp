class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int x = 0;
        int top = 0,left = 0;
        int bottom = n-1,right = n-1;
        while(top <= bottom && left <= right){
            for(int i=left;i<=right;i++){
                matrix[top][i] = ++x;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                matrix[i][right] = ++x;
            }
            right--;
            for(int i=right;i>=left;i--){
                matrix[bottom][i] = ++x;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                matrix[i][left] = ++x;
            }
            left++;
        }
        return matrix;
    }
};