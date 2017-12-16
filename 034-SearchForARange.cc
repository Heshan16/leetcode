/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firs,sec,l=0,r=nums.size()-1,mid;
        while(l<=r) {
            mid=(l+r)/2;
            if(target==nums[mid]){
                if(mid==0 || nums[mid-1]!=target)
                    break;
                r=mid-1;
            }
            else if(target>nums[mid])
                l=mid+1;
            else
                r=mid-1;
        }
        if(l>r)
            return vector<int>{-1,-1};
        firs=mid;
        
        l=0,r=nums.size()-1;
        while(l<=r) {
            mid=(l+r)/2;
            if(target==nums[mid]){
                 if(mid==nums.size()-1 || nums[mid+1]!=target)
                     break;
                l=mid+1;
            }
            else if(target>nums[mid])
                l=mid+1;
            else
                r=mid-1;
        }
        return vector<int>{firs,mid};
        
    }
};
