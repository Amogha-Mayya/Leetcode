class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        for(char c:text){
            if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n')
            {
                m[c]++;
            }
        }
        m['l']/=2;
        m['o']/=2;
        int mini = INT_MAX;
        for(auto it:m){
            cout<<it.first<<" "<<it.second<<endl;
            mini = min(mini,it.second);
        }
        if(m.size()!=5) return 0;
        return mini;
    }
};