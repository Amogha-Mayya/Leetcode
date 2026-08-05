class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>>m;
        vector<int>v;
        for(auto i:invocations){
            int a = i[0];
            int b = i[1];
            m[a].push_back(b);
        }
        vector<int> suspicious(n, 0);
        queue<int> q;
        q.push(k);
        suspicious[k] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : m[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = 1;
                    q.push(v);
                }
            }
        }
        for (auto &e : invocations) {
        int u = e[0];
        int v = e[1];

        if (!suspicious[u] && suspicious[v]) {
            vector<int> ans;
            for (int i = 0; i < n; i++)
                ans.push_back(i);
            return ans;
            }
        }
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};