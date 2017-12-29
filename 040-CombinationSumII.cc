/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:

[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        std::sort(candidates.begin(),candidates.end());
        recur_combi(res,cur,candidates,target,0,0);
        return res;
    }
    
    void recur_combi(vector<vector<int>> &res,vector<int> &cur,vector<int> &candidates,int target,int i,int sum) {
        if(sum==target)
            res.push_back(cur);
        int sz=candidates.size();
        for(int j=i;j<sz;j++) {
            if(sum+candidates[j]>target)
                break;
            if(j==i || candidates[j]!=candidates[j-1]) {
                cur.push_back(candidates[j]);
                recur_combi(res,cur,candidates,target,j+1,sum+candidates[j]);
                cur.pop_back();
            }
        }
    }
};
