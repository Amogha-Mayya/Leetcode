class Solution {
public:
typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        // take prefix sum of all the digits of string
        // [l,r] = digitsum[r] - digitsum[l-1]

        // number upto logic till every index 
        // [l,r] = numupto[r] - numupto[l-1] 

        // store number of non zero digits

        // PREPROCESS 
        // 1) digitsum 2) numberupto 3) non zero digits

        int n = s.length();
        int mod = 1e9+7;
        vector<int>nonzero(n,0);
        vector<ll>numberupto(n,0);
        vector<ll>digitsum(n,0);
        vector<ll>power(n+1,0);

        power[0] = 1;
        for(int i=1;i<=n;i++)
            power[i] = (power[i-1] * 10) % mod;
        
        nonzero[0] = (s[0] != '0')? 1:0;
        for(int i=1;i<n;i++){
            int digit = s[i] - '0';
            nonzero[i] = nonzero[i-1] + ((digit != 0)? 1:0);
        }

        numberupto[0] = s[0]-'0';
        for(int i=1;i<n;i++){
            int digit = s[i] - '0';
            if(digit != 0)
            numberupto[i] = ((numberupto[i-1]*10) + digit)%mod;
            else numberupto[i] = numberupto[i-1];
        }
        digitsum[0] = s[0] - '0';
        for(int i=1;i<n;i++){
            int digit = s[i] - '0';
            digitsum[i] = digitsum[i-1] + digit;
        }  
        int q = queries.size();
        vector<int>v;
        for(auto i:queries){
            int l = i[0];
            int r = i[1];
            // sum * x
            ll sum = digitsum[r] - ((l==0)? 0: digitsum[l-1]);
            int numbefore = (l==0)?0:numberupto[l-1];

            int k = nonzero[r] - ((l==0)? 0: nonzero[l-1]);
            ll x = (numberupto[r] - (numbefore*power[k]%mod) + mod)%mod;
            v.push_back((int)((x*sum)%mod));
        }
        return v;
    }
};