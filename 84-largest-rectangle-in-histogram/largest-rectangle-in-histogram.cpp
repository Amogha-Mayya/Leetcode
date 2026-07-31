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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n,0);
        vector<int>pse(n,0);
        solve(heights,nse);
        solve2(heights,pse);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int sum = 0;
            int left = i - pse[i];
            int right = nse[i] - i;
            sum += (left + right - 1) * heights[i];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};