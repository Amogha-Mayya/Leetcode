class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string str;
        for(char c:s){
            if(c=='('){
                count++;
                if(count>1)
                    str+=c;
            }
            else {
                if(count>1)
                    str+=c;
                count--;
            }
        }
        return str;
    }
};