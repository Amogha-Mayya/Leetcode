class Solution {
public:
typedef long long ll;
ll mod = 1e9+7;
int solve(int x,ll n){
    if(n == 0) return 1;
    ll half = solve(x,n/2);
    if(n%2 == 0) return (half*half)%mod;
    else return (half*half*x)%mod;
}
    int countGoodNumbers(long long n) {
        ll even = (n+1)/2;
        ll odd = n/2;
        return (1LL * solve(5,even) * solve(4,odd))%mod;
    }
};