/*
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:

[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(),nums.end());
        permute_recur(res,nums,0);
        return res;
    }
    void permute_recur(vector<vector<int>> &res,vector<int>& nums,int i) {
        if(i==nums.size()) {
            res.push_back(nums);
            return;
        }
        permute_recur(res,nums,i+1);
        for(int j=i+1;j<nums.size();j++) {
            if(nums[j]==nums[i])
                continue;
            swap(nums[i],nums[j]);
            permute_recur(res,nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
};
