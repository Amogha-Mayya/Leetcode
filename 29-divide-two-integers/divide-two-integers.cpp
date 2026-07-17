class Solution {
public:
typedef long long ll;
    int divide(int dividend, int divisor) {
       ll n = dividend;
       ll d = divisor;
       if(n == d) return 1;
       if(n == INT_MIN && d == -1) return INT_MAX;
       if(d == 1) return n;
       bool flag = false;
       if(n < 0 && d > 0) flag = true;
       if(n > 0 && d < 0) flag = true;
       n = abs(n);
       d = abs(d);

       ll sum = 0;
       ll ans = 0;

       while(sum + d <= n){
            sum+=d;
            ans++;
       }
       if(ans > INT_MAX && flag == false)
            return INT_MAX;
       if(ans > INT_MAX && flag == true)
            return INT_MIN;
       if(flag == false) return ans;
       else return -1 * ans;
    }
};