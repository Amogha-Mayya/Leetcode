class Solution {
public:
bool check_palindrome(string str){
    int l = 0;
    int r = str.size()-1;
    while(l<r){
        if(str[l] != str[r]) return false;
        l++;r--;
    }
    return true;
}
void solve(int idx,string s,vector<vector<string>>& v,
vector<string>& temp,int n){
    if(idx == n){
        v.push_back(temp);
        return;
    }
    for(int j=idx;j<n;j++){
        string str = s.substr(idx,j-idx+1);
        if(check_palindrome(str)){
            temp.push_back(str);
            solve(j+1,s,v,temp,n);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>v;
        vector<string>temp;
        solve(0,s,v,temp,n);
        return v;
    }
};