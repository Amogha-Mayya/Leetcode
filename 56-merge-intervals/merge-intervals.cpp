class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=1;i<n;i++){
            vector<int>& temp = v.back();
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(temp[1],intervals[i][1]);
            }
            else v.push_back(intervals[i]);
        }
        return v;
    }
};