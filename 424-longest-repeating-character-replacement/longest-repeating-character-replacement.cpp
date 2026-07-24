class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0,j=0;
        unordered_map<char,int>m;
        int maxi=0;
        int maxfreq = 0;
        while(j < n){
            m[s[j]]++;
            maxfreq = max(maxfreq,m[s[j]]);
            if((j-i+1) - maxfreq <= k){
                maxi = max(maxi,j-i+1);
                j++;
            }
            else{
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;
                j++;
            }
        }
        return maxi;
    }
};