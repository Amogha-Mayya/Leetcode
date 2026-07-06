class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        // merge interval
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>& prev = v.back();
            if(intervals[i][0] <= prev[1]){
                prev[1] = max(prev[1],intervals[i][1]);
            }
            else v.push_back(intervals[i]);
        }
        return v;
    }
};