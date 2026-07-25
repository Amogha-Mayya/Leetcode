class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            auto [word,count] = q.front();
            q.pop();
            if(word == endWord) return count;
            for(int i=0;i<word.size();i++){
                char temp = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        q.push({word,count+1});
                        s.erase(word);
                    }
                    word[i] = temp;
                }
            }
        }
        return 0;
    }
};