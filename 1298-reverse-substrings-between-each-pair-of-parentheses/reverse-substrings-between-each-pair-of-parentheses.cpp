class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch != ')') st.push(ch);
            else{
                deque<char>d;
                while(st.top() != '('){
                    d.push_back(st.top());
                    st.pop();
                }
                st.pop();
                while(!d.empty()){
                    char temp = d.front();
                    d.pop_front();
                    st.push(temp);
                }
            }
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};