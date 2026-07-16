class Solution {
public:
int solve(int mid,vector<int>& bloomDay,int k){
    int n = bloomDay.size();
    int bokets = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(bloomDay[i] <= mid)
            count++;
        else count = 0;
        if(count == k)
        {
            bokets++;
            count = 0;
        }
    }
    return bokets;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < 1LL*m*k) return -1;
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(solve(mid,bloomDay,k) >= m){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }   
        return ans;
    }
};