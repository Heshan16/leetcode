/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2. 
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,max_cont=0,cur_cont=0,sz=j;
        while(i!=j) {
            cur_cont=(sz--)*min(height[i],height[j]);
            (height[i]>height[j])?j--:i++;
            if(cur_cont>max_cont)
                max_cont=cur_cont;
        }
        return max_cont;
    }
};
