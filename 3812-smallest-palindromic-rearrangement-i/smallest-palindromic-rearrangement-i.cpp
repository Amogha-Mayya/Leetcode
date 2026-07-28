class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        int size = 0;
        if(n%2 == 0) size = n/2-1;
        else size = n/2-1;
        string temp = "";
        for(int i=0;i<=size;i++)
            temp += s[i];
        cout<<temp;
        sort(temp.begin(),temp.end());
        string ans = "";
        ans += temp;
        if(n%2 != 0) ans += s[size + 1];
        reverse(temp.begin(),temp.end());
        ans += temp;
        return ans;
    }   
};