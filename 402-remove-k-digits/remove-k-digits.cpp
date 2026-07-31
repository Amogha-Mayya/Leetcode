class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) return "0";
        stack<char>st;
        // trim of initial zero's
        // if n == k return 0
        // if we couldnt remove k elements take out last k digits
        int count = 0;
        for(int i=0;i<n;i++){
            char ch = num[i];
            while(!st.empty() && st.top() > ch){
                if(count == k) break;
                st.pop();
                count++;
            }
            st.push(ch);
        }
        while(count < k){
        st.pop();
        count++;
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        int cnt = 0;
        for(int i=0;i<result.size();i++){
            if(result[i] == '0') cnt++;
            else break;
        }
        string ans = result.substr(cnt,result.size()-cnt);
        if(ans == "") return "0";
        else return ans;
    }
};