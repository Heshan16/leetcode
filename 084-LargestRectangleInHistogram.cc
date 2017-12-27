/*
 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10. 

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> lowi;
        lowi.push(-1);
        int sz=heights.size(),ret=0;
        for(int i=0;i<sz;i++) {
            while(!lowi.empty() && heights[i]<heights[lowi.top()]) { //it must be <
                int h=heights[lowi.top()];
                lowi.pop();
                int lefti=lowi.empty()?-1:lowi.top();
                ret=max(ret,h*(i-lefti-1));
            }
            lowi.push(i);
        }
        return ret;
    }
};
