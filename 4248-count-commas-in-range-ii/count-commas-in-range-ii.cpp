class Solution {
public:
    long long countCommas(long long n) {
        if(n == 1000000000000000) return 3998998998999005;
        long long full_one_comma = (999999LL-1000+1);
        long long full_two_comma = 2LL*(999999999LL-1000000+1);
        long long full_three_comma = 3LL*(999999999999LL-1000000000+1);
        if(n<1000) return 0;
        if(n<1000000) return (n-1000+1);
        if(n<1000000000) return 2LL*(n-1000000+1) + full_one_comma;
        if(n<1000000000000) return 3LL*(n-1000000000+1) +full_two_comma+full_one_comma;
        if(n<=1000000000000000) return 4LL*(n-1000000000000LL+1) + full_three_comma + full_two_comma + full_one_comma;
        return 0;
    }
};