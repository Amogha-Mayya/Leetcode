class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        int count = 0;
        for(int i=1;i<n;i++){
            vector<int>& prev = v.back();
            if(intervals[i][0] < prev[1]){
                prev[1] = min(prev[1],intervals[i][1]);
                count++;
            }
            else v.push_back(intervals[i]);
        }
        return count;
    }
};