/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2

*/


class Solution {
public:
    int mySqrt(int x) {
        if(x<1)
            return 0;
        int res=2,cons=x/2;
        while(abs(res-cons)>1) {
            res=(res+cons)/2;
            cons=x/res;
        }
        return min(res,cons);
    }
};
