class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()) return false;
        for(int i=0;i<ransomNote.size();i++){
            if(find(magazine.begin(),magazine.end(),ransomNote[i])!=magazine.end()){
                int pos = find(magazine.begin(),magazine.end(),ransomNote[i])-magazine.begin();
                magazine.erase(pos,1);
            }
            else{
                return false;
            }
        }
        return true;
    }
};