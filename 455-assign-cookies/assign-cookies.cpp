class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        int n = g.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        while(i < n){
            if(j >= s.size()) break;
            if(g[i] <= s[j]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};