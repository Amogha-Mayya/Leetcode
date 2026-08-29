class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int ans = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
int temp = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if(temp <= drones[i][2]){
                if(temp < mini){
                    ans = i;
                    mini = temp;
                }
            }
        }
        return ans;
    }
};