/*
 Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]

Example 2:

Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]

*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int sz=nums.size(),i=0;
        for(int i=0;i<sz;i++) {
            int start=nums[i],end=nums[i];
            while(i+1<sz && nums[i+1]==end+1) 
                i++,end++;
            if(start==end)
                res.push_back(to_string(start));
            else 
                res.push_back(to_string(start)+"->"+to_string(end));
        }
        return res;
    }
};
