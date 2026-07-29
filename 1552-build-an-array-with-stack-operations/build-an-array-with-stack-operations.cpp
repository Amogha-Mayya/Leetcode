class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>v;
        stack<int>st;
        int count = 0;
        for(int i=1;i<=n;i++){
            if(count == target.size()) return v;
            if(find(target.begin(),target.end(),i) != target.end()){
                st.push(i);
                v.push_back("Push");
                count++;
            }
            else{
                v.push_back("Push");
                v.push_back("Pop");
            }
        }
        return v;
    }
};