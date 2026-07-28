class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int count = 0;
        for(char ch : s){
            if(ch == '(') st.push(ch);
            else{
                if(!st.empty()) st.pop();
                else count++;
            }
        }
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};