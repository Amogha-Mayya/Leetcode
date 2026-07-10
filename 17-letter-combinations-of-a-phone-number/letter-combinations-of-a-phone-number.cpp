class Solution {
public:
unordered_map<char,string>m;
void solve(int idx,string digits,string temp,vector<string>& v){
    if(idx == digits.size()){
        v.push_back(temp);
        return;
    }
    for(char ch:m[digits[idx]]){
        temp.push_back(ch);
        solve(idx+1,digits,temp,v);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string>v;
        string temp = "";
        solve(0,digits,temp,v);
        return v;
    }
};