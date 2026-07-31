class Solution {
public:
typedef pair<int,int>p;
static bool cmp(p a, p b){
    return a.second > b.second;
}
    int minimumPushes(string word) {
        unordered_map<char,int>m;
        for(char ch : word){
            m[ch]++;
        }
        vector<pair<int,int>>v;
        for(auto it : m)
            v.push_back({it.first,it.second});
        sort(v.begin(),v.end(),cmp);
        int total = 0;
        if(m.size() <= 8){
            for(auto it : v)
                total += (it.second);
        }
        else if(m.size() <= 16){
            for(int j=0;j<8;j++)
                total += (v[j].second);
            for(int j=8;j<m.size();j++)
                total += (2 * v[j].second);
        }
        else if(m.size() <= 24){
            for(int j=0;j<8;j++)
                total += (v[j].second);
            for(int j=8;j<16;j++)
                total += (2 * v[j].second);
            for(int j=16;j<m.size();j++)
                total += (3 * v[j].second);
        }
        else{
            for(int j=0;j<8;j++)
                total += (v[j].second);
            for(int j=8;j<16;j++)
                total += (2 * v[j].second);
            for(int j=16;j<24;j++)
                total += (3 * v[j].second);
            for(int j=24;j<m.size();j++)
                total += (4 * v[j].second);
        }
        return total;
    }
};