class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int maxi = 0, maxi2 = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            prefix[i] = maxi;
        }
        for(int i=n-1;i>=0;i--){
            maxi2 = max(maxi2,height[i]);
            suffix[i] = maxi2;
        }
        int total = 0;
        for(int i=0;i<n;i++){
            total += min(prefix[i],suffix[i]) - height[i];
        }
        return total;
    }
};