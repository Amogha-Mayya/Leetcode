class Solution {
public:
unordered_map<char,string>m = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};
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
        vector<string>v;
        string temp = "";
        solve(0,digits,temp,v);
        return v;
    }
};