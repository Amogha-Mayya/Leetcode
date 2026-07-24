class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int>m;
        int i=0,j=0;
        int k = 3;
        int n = s.size();
        int count = 0;
        while(j < n){
            m[s[j]]++;
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                if(m.size() == 3) count++;
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;j++;
            }
        }
        return count;
    }
};