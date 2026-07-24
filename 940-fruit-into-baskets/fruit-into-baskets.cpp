class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size() == 1) return 1;
        if(fruits.size() == 2) return 2;
        int k = 2;
        unordered_map<int,int>m;
        int i=0,j=0;
        int n = fruits.size();
        int maxi = 0;
        while(j < n){
            m[fruits[j]]++;
            if(m.size() <= k){
                maxi = max(maxi,j-i+1);
                j++;
            }
            else{
                while(m.size() > k){
                    m[fruits[i]]--;
                    if(m[fruits[i]] == 0) m.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};