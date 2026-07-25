class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        unordered_map<int,vector<int>>m;
        for(auto i:prerequisites){
            int a = i[0];
            int b = i[1];
            m[b].push_back(a);
        }
        vector<int>topo;
        vector<int>indegree(n,0);
        queue<int>q;
        for(auto i:m){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto i:m[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(topo.size() != n) return {};
        return topo;
    }
};