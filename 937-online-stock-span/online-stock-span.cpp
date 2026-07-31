class StockSpanner {
public:
stack<pair<int,int>>s;
    StockSpanner() {
    }
    
    int next(int price) {
        int total = 1;
        while(!s.empty() && s.top().first <= price){
            total += s.top().second;
            s.pop();
        }
        s.push({price,total});
        return total;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */