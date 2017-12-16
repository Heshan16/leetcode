/*
 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:

[
  [7],
  [2, 2, 3]
]
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //此题很像找钱问题
        vector<vector<int>> result;
        vector<int> cur;
        std::sort(candidates.begin(),candidates.end());
//notice 有序
        if(candidates.empty())
            return result;
        combinationsum_recur(result,cur,candidates,target,0,0);
        return result;
    }
    void combinationsum_recur(vector<vector<int>> &result,vector<int> &cur_vec,vector<int> &candidates,int target,int cur,int index) {
        if(cur==target)
            result.push_back(cur_vec);
//理清for循环用意极其重要，其包含了剪枝的，当当前元素也加不进来时，直接剪枝退出
        for(int i=index;i<candidates.size() && cur+candidates[i]<=target;i++) { //notice the check condition
            cur_vec.push_back(candidates[i]);
            combinationsum_recur(result,cur_vec,candidates,target,cur+candidates[i],i);
            cur_vec.pop_back();
        }
    }
};

