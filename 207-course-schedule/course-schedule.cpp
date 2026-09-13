class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indegree(n,0);
        unordered_map<int,vector<int>>m;
        for(auto i:prerequisites){
            int a = i[0];
            int b = i[1];
            indegree[a]++;
            m[b].push_back(a);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
            if(indegree[i] == 0) q.push(i);
        
        vector<int>v;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            v.push_back(node);
            for(auto i:m[node]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        return (v.size() == n);
    }
};