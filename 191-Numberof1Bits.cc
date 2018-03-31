class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        for(;n;res++) {
            n=n&(n-1);
        }
        return res;
    }
};
