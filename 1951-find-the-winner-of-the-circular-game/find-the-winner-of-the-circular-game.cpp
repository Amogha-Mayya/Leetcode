class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>arr;
        int idx = 0;
        k-=1;
        for(int i=1;i<=n;i++)
            arr.push_back(i);
        for(int i=1;i<n;i++){
            idx = (idx + k)%arr.size();
            arr.erase(arr.begin() + idx);
        }
        return arr[0];
    }
};