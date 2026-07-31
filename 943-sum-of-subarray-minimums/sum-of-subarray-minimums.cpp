class Solution {
public:
void solve(vector<int>& nse,vector<int>& arr){
    stack<int>st;
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(st.empty()) nse[i] = arr.size();
        else nse[i] = st.top();
        st.push(i);
    }
}
void solve2(vector<int>& pse,vector<int>& arr){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();
        st.push(i);
    }
}
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse(n,0);
        vector<int>pse(n,0);
        solve(nse,arr);
        solve2(pse,arr);
        int total = 0;
        int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};