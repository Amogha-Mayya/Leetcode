class Solution {
public:
    bool checkValidString(string s) {
        int maxopen = 0, minopen = 0;
        for(char ch : s){
            if(ch == '('){
                maxopen++;
                minopen++;
            }
            else if(ch == ')'){
                maxopen--;
                minopen--;
            }
            else{
                maxopen++;
                minopen--;
            }
            if(maxopen < 0) return false;
            minopen = max(minopen,0);
        }
        return minopen == 0;
    }
};