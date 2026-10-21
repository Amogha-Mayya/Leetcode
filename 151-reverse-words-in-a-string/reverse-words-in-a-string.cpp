class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string str;
        for(char c:s){
            if(c==' '){
                if(!str.empty())
                v.push_back(str);
                str="";
            }
            else{
                str+=c;
            }
        }
        if(!str.empty()) v.push_back(str);
        reverse(v.begin(),v.end());
        string res;
        for(auto i:v)
            res+=(i+" ");
        int n = res.size();
        res.erase(n-1);
        return res;
    }
};