class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int>diff(2051,0);
        for(auto i:logs){
            int birth = i[0];
            int death = i[1];
            int val = 1;
            diff[birth]+=val;
            if(death <= 2050)
            diff[death]-=val;
        }
        // prefix sum
        int sum = 0;
        int ans = 1950;
        int maxi = 0;
        for(int i=1950;i<=2050;i++){
            sum += diff[i];
            if(sum > maxi){
                ans = i;
                maxi = sum;
            }
        }
        return ans;
    }
};