/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,i=1;
        if(nums.empty())
            return 0;
        while(i<nums.size()) {
            if(nums[i]==nums[j])
                i++;
            else 
                nums[++j]=nums[i++];
        }
        nums.erase(nums.begin()+j+1,nums.end());
        return j+1;
    }
};
