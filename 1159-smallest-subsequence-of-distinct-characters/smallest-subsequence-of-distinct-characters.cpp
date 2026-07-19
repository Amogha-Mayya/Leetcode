class Solution {
public:
    string smallestSubsequence(string s) {
        // last index of every character
        vector<int>last(26);
        vector<bool>taken(26,false);
        for(int i=0;i<s.size();i++){
            last[s[i] - 'a'] = i;
        }
        string temp = "";
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int idx = s[i] - 'a';

            if(taken[idx] == true) continue;

            while(temp.length() > 0 && temp.back() > ch 
            && last[temp.back() - 'a'] > i){
                taken[temp.back() - 'a'] = false;
                temp.pop_back();
            }
            temp.push_back(s[i]);
            taken[idx] = true;
        }
        return temp;
    }
};