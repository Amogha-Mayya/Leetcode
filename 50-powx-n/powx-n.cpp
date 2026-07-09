class Solution {
public:
typedef long long ll;
double solve(double x,ll N){
    if(N == 0) return 1.0;
    double half = solve(x,N/2);
    if(N%2 == 0) return half * half;
    else return half * half * x;
}
    double myPow(double x, int n) {
        bool flag = false;
        ll N = n;
        if(n < 0){
            flag = true;
            N *= -1;
        }
        if(flag == true){
            double ans = solve(x,N);
            return 1/ans;
        }
        else return solve(x,N);
    }
};