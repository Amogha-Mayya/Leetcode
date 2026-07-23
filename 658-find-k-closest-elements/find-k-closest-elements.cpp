class Solution {
public:
typedef pair<int,int> pp;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>v;
        priority_queue<pp,vector<pp>,greater<pp>>q;
        for(auto i:arr){
            q.push({abs(i-x),i});
        }
        for(int i=0;i<k;i++){
            v.push_back(q.top().second); q.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};