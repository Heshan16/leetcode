/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0,buyp=INT_MAX;
        for(auto i:prices) {
            (i<buyp)?(buyp=i):res=max(i-buyp,res);
        }
        return res;
    }
};
