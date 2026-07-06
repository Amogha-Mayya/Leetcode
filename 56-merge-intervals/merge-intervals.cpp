class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>&prev = v.back();
            if(intervals[i][0] <= prev[1]){
                prev[1] = max(intervals[i][1],prev[1]);
            }
            else v.push_back(intervals[i]);
        }
        return v;
    }
};