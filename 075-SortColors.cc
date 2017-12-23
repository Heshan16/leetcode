/*
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem. 
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int less=-1,greater=nums.size(),i=0;
        while(i<greater) {
            if(nums[i]<1)
                swap(nums[i++],nums[++less]);
            else if(nums[i]>1)
                swap(nums[i],nums[--greater]);
            else
                i++;
        }
    }
};
