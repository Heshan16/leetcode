/*
 Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one. 
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t1=0,t2=0;
        for(auto cur:nums) {
            t1=(t1 ^ cur)&(~t2);
            t2=(t2 ^ cur)&(~t1);
        }
        return t1;
    }
};
