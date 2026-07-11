class Solution {
public:
int partition(vector<int>& arr,int low,int high){
    int piv = arr[high];
    int i = low-1;
    for(int j=low;j<=high;j++){
        if(arr[j] < piv){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
int quick_select(vector<int>& arr,int low,int high,int k){
    if(low > high) return -1;
    int pivot = partition(arr,low,high);
    if(pivot == k) return arr[pivot];
    else if(pivot < k)
        return quick_select(arr,pivot+1,high,k);
    else return quick_select(arr,low,pivot-1,k);
}
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        k=n-k;
        return quick_select(nums,low,high,k);
    }
};