class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        // first find out overlapping intervals
        vector<int>temp = intervals[0];
        int overlapping = 0;
        for(int i=1;i<n;i++){
            vector<int>&prev = temp;
            if(intervals[i][0] < prev[1])
            {
                cout<<i<<" ";
                overlapping++;
                prev[1] = min(prev[1],intervals[i][1]);
            }
            else temp = intervals[i];
        }
        return overlapping;
    }
};