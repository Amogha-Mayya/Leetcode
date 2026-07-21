class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count = 0;
        int i = 0, j = 0;
        int m = g.size() , n = s.size();
        while(i < m){
            if(j >= n) break;
            if(g[i] <= s[j]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};