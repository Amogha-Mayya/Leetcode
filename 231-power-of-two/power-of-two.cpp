class Solution {
public:
bool solve(int n){
    if(n == 0) return false;
    if(n == 1) return true;
    if(n%2 == 0)  return solve(n/2);
    else return false;
}
    bool isPowerOfTwo(int n) {
        return solve(n);
    }
};