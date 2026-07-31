class Solution {
public:
vector<int> nse(vector<int>&arr){
    int n = arr.size();
    vector<int>v1(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if(st.empty()) v1[i]=n;
        else v1[i]=st.top();
        st.push(i);
    }
    return v1;
}
vector<int> pse(vector<int>&arr){
    int n = arr.size();
    vector<int>v2(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if(st.empty()) v2[i]=-1;
        else v2[i]=st.top();
        st.push(i);
    }
    return v2;
}
vector<int> nge(vector<int>&arr){
    int n = arr.size();
    vector<int>v1(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if(st.empty()) v1[i]=n;
        else v1[i]=st.top();
        st.push(i);
    }
    return v1;
}
vector<int> pge(vector<int>&arr){
    int n = arr.size();
    vector<int>v2(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if(st.empty()) v2[i]=-1;
        else v2[i]=st.top();
        st.push(i);
    }
    return v2;
}
    long long subArrayRanges(vector<int>& nums) {
        vector<int>v1 = nse(nums);
        vector<int>v2 = pse(nums);
        vector<int>v3 = nge(nums);
        vector<int>v4 = pge(nums);
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            int left = i - v2[i];
            int right = v1[i] - i;
            int left2 = i - v3[i];
            int right2 = v4[i] - i;
            long long freq = (left*right*1LL*nums[i]);
            long long freq2 = (left2*right2*1LL*nums[i]);
            sum = sum + (freq2 - freq);
        }
        return sum;
    }
};