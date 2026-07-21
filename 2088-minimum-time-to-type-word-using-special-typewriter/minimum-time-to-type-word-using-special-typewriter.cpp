class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        int sum = 0;
        char prev = 'a';
        for(auto ch:word){
            int d1 = abs(ch - prev);
            int d2 = 26 - d1;
            cout<<d1<<" "<<d2<<endl;
            if(d1 < 0) d1 = INT_MAX;
            if(d2 < 0) d2 = INT_MAX;
            sum += min(d1,d2);
            prev = ch;
        }
        return sum + n;
    }
};