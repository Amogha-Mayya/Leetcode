class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>diff(n,0);   
        int val = 0;
        for(auto i:shifts){
            int start = i[0];
            int end = i[1];
            int direction = i[2];
            if(direction == 1) val = 1;
            else val = -1;
            diff[start]+=val;
            if(end + 1 < n)
            diff[end + 1]-=val;
        }
        // take prefix sum
        for(auto i:diff)
            cout<<i<<" ";
        int sum = 0;
        string prefix = s;
        for(int i=0;i<n;i++){
            sum += diff[i];
            cout << i << " " << sum << "\n";
            int ch = prefix[i] + sum;
            if(ch > 'z') while(ch > 'z') ch-=26;
            if(ch < 'a') while(ch < 'a') ch+=26;
            prefix[i] = ch;
        }
        return prefix;
    }
};