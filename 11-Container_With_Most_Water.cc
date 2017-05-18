/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. 
*/

//对于任意ai,aj,水的容量为(j-i)*min(ai,aj)
//故知，可一一遍历，对比找出最大值，显然在min(ai,aj)固定不变的情况下（j,i)的差值愈大愈好
//所以在段板大小不变的情况下，减少j,i差值是不会得出更大的容量的
//所以，我们可以先求两端点所围成的容量，然后每次将短板所在的地方进行移动，
//如为右版ndexr--,如左，则indexl++，
//每次的新板若比旧短板更小或相同，则不必比较，继续寻找下一板即可
//如此，经过o(n)时间，即找出最大的水容量

    int maxArea(vector<int>& height) {
        int maxv=0;
        int sz=height.size();
        if(sz<2)
            return 0;
        int i=0,j=sz-1;
        while(i<j){
            int h=min(height[i],height[j]);
            maxv=max(maxv,h*(j-i));
            while(height[i]<=h)
                i++;
            while(height[j]<=h)
                j--;
        }
        return maxv;
    }
