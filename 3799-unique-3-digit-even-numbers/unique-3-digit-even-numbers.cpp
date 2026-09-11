class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if((i==j) || (j==k) || (k==i)) continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num >= 100 && num <= 999 && num%2 == 0){
                        s.insert(num);
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                for(int k=n-1;k>=0;k--){
                    if((i==j) || (j==k) || (k==i)) continue;
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num >= 100 && num <= 999 && num%2 == 0){
                        s.insert(num);
                    }
                }
            }
        }
        return s.size();

    }
};