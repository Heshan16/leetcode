/*
 Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz=nums.size(),i=0;
        for(i=0;i<sz;i++) {
            while(nums[i]>0 && nums[i]<=sz && nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(i=0;i<sz && nums[i]==i+1;i++) 
            ;
        return i+1;
    }
};
