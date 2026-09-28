class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        string temp1 = "";
        string temp2 = "";
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                temp1.push_back(s[i]);
            }
            else{
                temp2.push_back(s[i]);
            }
        }
        string result = "";
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                result.push_back(temp1.back());
                temp1.pop_back();
            }
            else{
                result.push_back(temp2.back());
                temp2.pop_back();
            }
        }
        return result;
    }
};