class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        for(auto i:knowledge){
            string a = i[0];
            string b = i[1];
            m[a] = b;
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                string temp = "";
                while(s[++i] != ')'){
                    temp += s[i];
                }
                if(m[temp] != "")
                    ans += m[temp];
                else ans += '?';
            }
            else ans+=s[i];
        }
        return ans;
    }
};