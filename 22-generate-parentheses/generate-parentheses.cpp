class Solution {
public:
void solve(int open,int close,vector<string>& v,string temp,int n){
    if(temp.size() == 2*n){
        v.push_back(temp);
        return;
    }
    if(open < n)
    solve(open+1,close,v,temp + '(',n);
    if(open > close)
    solve(open,close+1,v,temp + ')',n);
}
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string temp = "";
        solve(0,0,v,temp,n);
        return v;
    }
};