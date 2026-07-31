class Solution {
public:
void solve(vector<int>& heights,vector<int>& nse){
    stack<int>st;
    for(int i=heights.size()-1;i>=0;i--){
        while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
        if(st.empty()) nse[i] = heights.size();
        else nse[i] = st.top();
        st.push(i);
    }
}
void solve2(vector<int>& heights,vector<int>& pse){
    stack<int>st;
    for(int i=0;i<heights.size();i++){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();
        st.push(i);
    }
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = INT_MIN;
        vector<int>heights(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            vector<int>nse(n,0);
            vector<int>pse(n,0);
            solve(heights,nse);
            solve2(heights,pse);
            for(int i=0;i<n;i++){
                int sum = 0;
                int left = i - pse[i];
                int right = nse[i] - i;
                sum += (left + right - 1) * heights[i];
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};