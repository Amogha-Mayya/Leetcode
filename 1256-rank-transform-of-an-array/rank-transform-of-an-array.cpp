class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp = arr;
        unordered_map<int,int>m;
        sort(temp.begin(),temp.end());
        int x = 1;
        for(auto i:temp){
            if(m[i]) continue;
            else m[i] = x++;
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(m[arr[i]]);
        }
        return v;
    }
};