/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int end=nums.size(),beg=0,mid=end/2;
        if(nums[0]>nums[1] || nums[end-1]>nums[end-2])
            return (nums[0]>nums[1])?0:end-1;
        beg=1,end=end-1;
        while(nums[mid+1]>nums[mid] || nums[mid-1]>nums[mid]) {
            if(nums[mid+1]>nums[mid]) 
                beg=mid+1;
            else
                end=mid-1;
           mid=(beg+end)/2;
        }
        return mid;
    }
};
