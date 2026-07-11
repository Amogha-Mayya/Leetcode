class Solution {
public:
unordered_set<string>st;
vector<int> dp = vector<int>(301, -1);
bool solve(int idx,string& s,int n){
    if(idx == n) return true;
    if(dp[idx] != -1) return dp[idx];
    for(int l=1;l<=n;l++){
        string temp = s.substr(idx,l);
        if(st.count(temp) && solve(idx + l,s,n)) 
            return dp[idx] = true;
    }
    return dp[idx] = false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto i:wordDict)
            st.insert(i);
        return solve(0,s,n);
    }
};