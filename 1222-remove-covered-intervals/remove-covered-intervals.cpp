class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        set<int>s;
        // forward
        for(int i=0;i<n-1;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            for(int j=i+1;j<n;j++){
                int c = intervals[j][0];
                int d = intervals[j][1];
                if((c <= a) && (b <= d))
                    s.insert(i);
            }
        }
        // backward
        for(int i=0;i<n-1;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            for(int j=i+1;j<n;j++){
                int c = intervals[j][0];
                int d = intervals[j][1];
                if((c >= a) && (b >= d))
                    s.insert(j);
            }
        }
        return n - s.size();
    }
};