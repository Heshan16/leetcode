/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1,res=0,level=0;
        while(i<j) {
            int min=(height[i]<=height[j])?height[i++]:height[j--];
            level=max(level,min);
            res+=level-min;
        }
        return res;
    }
};
