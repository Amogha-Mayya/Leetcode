class Solution {
public:
long long calculate(int mid,vector<int>& piles){
    long long hours = 0;
    for(int i=0;i<piles.size();i++){
        hours += ceil((double)piles[i]/mid);
    }
    return hours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(calculate(mid,piles) <= h)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};