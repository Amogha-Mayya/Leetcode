class Solution {
public:
typedef long long ll;
bool can_defeat(vector<int>& monsters, vector<ll>& bonus, 
ll mid,int n){
    ll initial = mid;
    for(int i=0;i<n;i++){
        if(initial + bonus[i] < monsters[i]) return false;
        else{
            initial-=monsters[i];
            if(initial < 0) initial = 0;
        }
    }
    return true;
}
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        ll low = 0;
        ll high = accumulate(monsters.begin(),monsters.end(),0LL);

        vector<ll>temp(n,0);
        for(auto i:boosts){
            ll left = i[0];
            ll right = i[1];
            ll value = i[2];
            temp[left]+=value;
            if(right + 1 < n)
            temp[right + 1]-=value;
        }
        // take prefix sum
        ll sum = 0;
        vector<ll>bonus(n,0);
        for(ll i=0;i<n;i++){
            sum += temp[i];
            bonus[i] = sum;
        }
        // bonus array + initial strength (?)
        ll ans = high;
        while(low <= high){
            ll mid = low + (high-low)/2;
            if(can_defeat(monsters,bonus,mid,n)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};