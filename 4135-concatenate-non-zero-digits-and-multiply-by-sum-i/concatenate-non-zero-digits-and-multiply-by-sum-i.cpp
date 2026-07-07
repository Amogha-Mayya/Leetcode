class Solution {
public:
typedef long long ll;
    long long sumAndMultiply(int n) {
        ll sum = 0;
        ll temp = 0,temp2 = 0;
        while(n){
            if((n%10)!=0)
                temp = temp * 10 + (n%10);
            n/=10;
        }
        while(temp){
            temp2 = temp2 * 10 + (temp%10);
            temp/=10;
        }
        ll copy = temp2;
        while(temp2){
            sum += (temp2%10);
            temp2/=10;
        }
        return sum * copy;
    }
};