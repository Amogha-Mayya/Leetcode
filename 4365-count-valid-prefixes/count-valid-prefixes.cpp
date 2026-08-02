class Solution {
public:
    int countValidPrefixes(string s) {
        int one = 0;
        int zero = 0;
        int count = 0;
        for(char ch : s){
            if(ch == '0') zero++;
            else one++;
            if(abs(zero - one) <= 1) count++;
        }
        return count;
    }
};