class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp;
        for(char c : s)
            mp[c]++;
        for(char c : t)
            mp[c]--;
        int steps = 0;
        for(auto it : mp){
            if(it.second > 0)
                steps += it.second;
        }

        return steps;
    }
};