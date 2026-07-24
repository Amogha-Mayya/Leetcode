class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int i=0,j=0;
        int n = s.size();
        int maxi = 0;
        while(j < n){
            m[s[j]]++;
            if(m.size() < j-i+1){
                while(m.size() < j-i+1){
                    m[s[i]]--;
                    if(m[s[i]] == 0) m.erase(s[i]);
                    i++;
                }
                j++;
            }
            else if(m.size() == j-i+1){
                maxi = max(maxi,j-i+1);
                j++;
            }
        }
        return maxi;
    }
};