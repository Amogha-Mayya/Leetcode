class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>v;
        queue<int>q;
        for(int i=1;i<9;i++)
            q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(x >= low && x <= high)
                v.push_back(x);
            int digit = x % 10;
            if(digit + 1 <= 9){
                int xn = (x * 10) + (digit + 1);
                q.push(xn);
            }
        }
        return v;
    }
};