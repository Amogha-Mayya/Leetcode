class Solution {
public:
bool check_palindrome(string& str){
    int i=0;
    int j = str.size()-1;
    while(i<j){
        if(str[i] != str[j]) return false;
        i++;j--;
    }
    return true;
}
void solve(int idx,string s,vector<vector<string>>& v,
vector<string>& temp){
    if(idx == s.size()){
        v.push_back(temp);
        return;
    }
    for(int j=idx;j<s.size();j++){
        string str = s.substr(idx,j-idx+1);
        if(check_palindrome(str)){
            temp.push_back(str);
            solve(j+1,s,v,temp);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        vector<string>temp;
        solve(0,s,v,temp);
        return v;
    }
};