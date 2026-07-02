class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        vector<string>v;
        string temp = "";
        for(int i=0;i<n;i++){
            if(s[i] != ' ')
                temp+=s[i];
            else{
                if(temp != ""){
                    v.push_back(temp);
                }
                temp = "";
            }
        }
        if(temp != "")
        v.push_back(temp);
        return v.size();
    }
};