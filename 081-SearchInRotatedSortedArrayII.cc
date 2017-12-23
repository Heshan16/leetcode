/*


    Follow up for "Search in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
*/

//average cost is O(logn),in worst case,it's O(n)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return binary_search(nums,target,0,nums.size()-1);
    }
    bool binary_search(vector<int> &nums,int target,int beg,int end) {
        if(beg>=end)
            return (beg==end) && nums[beg]==target?true:false;
        int middle=(beg+end)/2;
        if(nums[beg]==target || nums[middle]==target || nums[end]==target)
            return true;
        if(nums[beg]<nums[middle] || nums[middle]>nums[end])
            return nums[middle]>target && nums[beg]<target ? binary_search(nums,target,beg+1,middle-1):binary_search(nums,target,middle+1,end-1);
        else if(nums[beg]>nums[middle] || nums[middle]<nums[end])
            return nums[middle]<target && nums[end]>target ? binary_search(nums,target,middle+1,end):binary_search(nums,target,beg+1,middle-1);
        return binary_search(nums,target,middle+1,end) || binary_search(nums,target,beg+1,middle-1);
    }
};
