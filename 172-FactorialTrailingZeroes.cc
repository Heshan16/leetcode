class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        for(long long i=5;i<=n;i*=5)
            res+=(long long)n/i;
        return res;
    }
};
