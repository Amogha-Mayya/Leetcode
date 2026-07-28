class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int x = 0, y = 0;
        for(auto i:tokens){
            if(i == "+"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(x + y);
            }
            else if(i == "*"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(x * y);
            }
            else if(i == "/"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(y / x);
            }
            else if(i == "-"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(y - x);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};