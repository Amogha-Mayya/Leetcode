class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>v;
        for(int i=1;i<=n;i++){
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto i:v){
            ans.push_back(stoi(i));
        }
        return ans;
    }
};