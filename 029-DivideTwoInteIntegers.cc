#include<string>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)
            return -1;
        bool minus=((dividend>0) && divisor>0) || (dividend<0 && divisor<0)?false:true;
        long long divd=dividend>0?dividend:-(long long)dividend;
        long long divs=divisor>0?divisor:-(long long)divisor; //可能越界
        if(divd<divs)
            return 0;
        int res=0;
        long long div=divs;
        while(div<=divd) {
            div<<=1;
            res++;
        }
        long long result=(long long)1<<--res; //notice 
        divd-=divs<<res;
        
        while(divd>=divs) {
            if(divd>=(divs<<--res)) {
                divd-=divs<<res;
                result|=1<<res;
            }
        }
        result= minus?-result:result;
        if(result>INT_MAX)
            return INT_MAX;
        if(result<INT_MIN)
            return INT_MIN;
        return result;
    }
};
