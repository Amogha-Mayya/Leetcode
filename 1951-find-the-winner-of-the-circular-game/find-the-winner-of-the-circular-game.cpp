class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++)
            v.push_back(i);
        int idx = 0;
        for(int i=1;i<n;i++){
            idx+=(k-1);
            idx%=(v.size());
            cout<<idx<<" ";
            v.erase(v.begin() + idx);
        }
        return v[0];
    }
};