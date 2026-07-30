class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int size = n * 2;
        stack<int>st;
        vector<int>v(n,0);
        for(int i=size-1;i>=0;i--){
            int j = i;
            if(i >= size/2) j = j-n;
            while(!st.empty() && st.top() <= nums[j]) st.pop();
            if(i < size/2){
                if(st.empty()) v[j] = -1;
                else v[j] = st.top();
            }
            st.push(nums[j]);
        }
        return v;
    }
};