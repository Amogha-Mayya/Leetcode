class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int count = 0;
        for(auto i:patterns){
            if(word.contains(i)) count++;
        }
        return count;
    }
};