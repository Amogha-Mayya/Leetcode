class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>q;
        q.push(a); q.push(b); q.push(c);
        int count = 0;
        while(q.size() >= 2){
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            if(x-1 > 0) q.push(--x);
            if(y-1 > 0) q.push(--y);
            count++;
        }
        return count;
    }
};