class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0;
        int n = arr.size();
        int sum = 0, count = 0;
        double avg = 0;
        while(j < n){
            sum += arr[j];
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                avg = sum/k;
                sum-=arr[i];
                if(avg >= threshold) count++;
                i++;
                j++;
            }
        }
        return count;
    }
};