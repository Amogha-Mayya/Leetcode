class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:arr){
            pq.push(i);
        }
        unordered_map<int,int>m;
        int temp = 1;
        while(!pq.empty()){
            int x = pq.top();
            m[x] = temp;
            pq.pop();
            if(x != pq.top()) temp++;
        }
        vector<int>v;
        for(auto i:arr)
            v.push_back(m[i]);
        return v;
    }
};