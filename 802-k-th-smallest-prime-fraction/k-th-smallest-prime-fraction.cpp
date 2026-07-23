class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>>q;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                q.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
                if(q.size() > k) q.pop();
            }
        }
        return {q.top().second.first,q.top().second.second};
    }
};