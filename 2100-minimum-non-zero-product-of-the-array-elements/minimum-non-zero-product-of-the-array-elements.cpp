class Solution {
public:
typedef long long ll;
ll mod = 1e9+7;
ll solve(ll x,ll n){
    if(n == 0) return 1;
    x%=mod;
    ll half = solve(x,n/2)%mod;
    if(n%2 == 0) return (half*half)%mod;
    else return (((half*half)%mod)*x)%mod;
}
    int minNonZeroProduct(int p) {
        ll m = (1LL<<p)-1;
        ll exp = (m-1)/2;
        return __int128(m%mod * solve(m-1,exp))%mod;
    }
};