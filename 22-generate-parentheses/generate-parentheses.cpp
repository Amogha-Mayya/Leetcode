class Solution {
public:
void solve(int open,int close,string temp,int n,vector<string>& v){
    if(close == n){
        v.push_back(temp);
        return;
    }
    // pick (
    if(open < n)
    solve(open+1,close,temp + '(',n,v);
    // pick )
    if(open > close)
    solve(open,close+1,temp + ')',n,v);
}
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string temp;
        solve(0,0,temp,n,v);
        return v;
    }
};