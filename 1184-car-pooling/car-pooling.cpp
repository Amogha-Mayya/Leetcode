class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1001,0);
        for(auto i:trips){
            int num = i[0];
            int from = i[1];
            int to = i[2];
            diff[from]+=num;
            diff[to]-=num;
        }
        // take prefix sum
        int sum = 0;
        for(int i=0;i<=1000;i++){
            sum+=diff[i];
            cout<<sum<<" ";
            if(sum > capacity) return false;
        }
        return true;
    }
};