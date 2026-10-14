class Solution {
public:
typedef long long ll;
    string maxSumOfSquares(int num, int sum) {
        
        string good = "";
        int copy = sum;
        for(int i=0;i<num;i++){
            int test = 9;
            while(test >= 0){
                if(sum >= test  && test >= 0) {
                    good += (test + '0');
                    sum -= test;
                    break;
                }
                else test--;
            }
        }
        int temp = 0;
        cout<<good<<endl;
        for(auto i:good) 
            temp+=(i - '0');
        if(temp != copy) return "";
        return good;
    }
};