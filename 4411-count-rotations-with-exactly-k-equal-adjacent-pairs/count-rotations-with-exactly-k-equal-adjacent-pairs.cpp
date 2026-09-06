class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            string temp = s;
            rotate(temp.begin(),temp.begin() + i,temp.end());
            int count = 0;
            for(int i=1;i<temp.size();i++){
                if(temp[i] == temp[i-1]) count++;
            }
            if(count == k) ans++;
        }
        return ans;
    }
};