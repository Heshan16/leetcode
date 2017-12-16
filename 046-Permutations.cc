/*


Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute_recur(res,nums,0);
        return res;
    }
    void permute_recur(vector<vector<int>> &res,vector<int>& nums,int i) {
        if(i==nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++) {
            swap(nums[i],nums[j]);
            permute_recur(res,nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
}
