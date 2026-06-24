class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int>q;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            st.push(sandwiches[i]);
        }
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int count = 0;
        while(!q.empty()){
            if(count > q.size()) break;
            if(q.front() == st.top())
            {
                q.pop();
                st.pop();
                count = 0;
            }
            else{
                int x = q.front();
                q.pop();
                q.push(x);
                count++;
            }
        }
        return q.size();
    }
};