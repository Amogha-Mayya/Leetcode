class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>v;
        int count = 0;
        for(int i=1;i<=n;i++){
        if(find(target.begin(),target.end(),i) != target.end()){
                v.push_back("Push");
                count++;
            }
            else{
                v.push_back("Push");
                v.push_back("Pop");
            }
            if(target.size() == count) return v;
        }
        return v;
    }
};