class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>& temp = v.back();
            if(temp[1] >= intervals[i][0])
                temp[1] = max(temp[1],intervals[i][1]);
            else v.push_back(intervals[i]);
        }
        return v;
    }
};