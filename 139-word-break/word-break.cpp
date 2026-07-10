class Solution {
public:
unordered_set<string>st;
bool solve(int idx,string s,int n,vector<int>& dp){
    if(idx == n){
        return true;
    }
    if(dp[idx] != -1) return dp[idx];
    for(int l=1;l<=n;l++){
        string temp = s.substr(idx,l);
        if(st.find(temp) != st.end()
        && solve(idx+l,s,n,dp)) return dp[idx] = true;
    }
    return dp[idx] = false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto i:wordDict)
            st.insert(i);
        vector<int>dp(n,-1);
        return solve(0,s,n,dp);
    }
};