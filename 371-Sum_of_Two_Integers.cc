class Solution {
public:
    int getSum(int a, int b) {
        if(a&b)
            return getSum((a&b)<<1,a^b);
        return a|b;
    }
};
