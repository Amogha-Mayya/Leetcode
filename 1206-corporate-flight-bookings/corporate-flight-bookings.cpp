class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // Difference Array Technique
        vector<int>diff(n+1,0);
        for(auto i:bookings){
            int left = i[0];
            int right = i[1];
            int value = i[2];
            diff[left]+=value;
            if(right+1 <= n)
            diff[right+1]-=value;
        }
        // take prefix sum
        vector<int>v;
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum+=diff[i];
            v.push_back(sum);
        }
        return v;
    }
};