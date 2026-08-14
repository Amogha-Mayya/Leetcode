class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i=0,j=0;
        int maxi = 0;
        unordered_map<char,int>m;
        while(j < n){
            m[s[j]]++;
            while(m[s[j]] > 2){
                m[s[i]]--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};