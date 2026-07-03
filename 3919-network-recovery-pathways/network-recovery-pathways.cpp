class Solution {
public:
typedef long long ll;
typedef pair<long long,int>P;
bool check(int mid,int n,ll k,unordered_map<int,vector<vector<int>>>& m){
    vector<ll>result(n,LLONG_MAX);
    priority_queue<P,vector<P>,greater<P>>q;

    result[0] = 0;
    q.push({0,0});
    while(!q.empty()){
        auto [d,node] = q.top();
        q.pop();
        if(d > k) return false;
        if(node == n-1) return true;
        if(result[node] < d) continue;
        for(auto i:m[node]){
            int neigh = i[0];
            int cost = i[1];
            if(cost < mid) continue;
            if(d + cost < result[neigh]){
                result[neigh] = d + cost;
                q.push({d + cost,neigh});
            }
        }
    }
    return false;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        // source = 0 , destination = n-1
        // valid path = all nodes online , total cost <= k
        // score = min(c1,c2,c3,cn)
        // ans = maximum score for any valid path

        // dont add offline edges to adjacency list
        int n = online.size();
        int l = INT_MAX;
        int r = 0;
        unordered_map<int,vector<vector<int>>>m;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            int c = i[2];
            if(online[a] & online[b]){
                m[a].push_back({b,c});
                l = min(l,c);
                r = max(r,c);
            }
        }
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(mid, n, k, m)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};