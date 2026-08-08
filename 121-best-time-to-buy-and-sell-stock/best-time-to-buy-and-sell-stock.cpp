class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minibuy = INT_MAX,maxprofit = INT_MIN;
        for(int i=0;i<n;i++){
            minibuy = min(minibuy,prices[i]);
            maxprofit = max(maxprofit,prices[i] - minibuy);
        }
        return maxprofit;
    }
};