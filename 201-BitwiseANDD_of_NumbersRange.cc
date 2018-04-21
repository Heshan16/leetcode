class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t=m^n,sum=0,cur=0;
        while(t){
            cur|=(1<<(sum++));
            t>>=1;
        }
        return (m|n)&(~cur);
    }
};
