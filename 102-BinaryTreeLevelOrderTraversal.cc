/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        buildvec(res,root,0);
        return res;
    }
    void buildvec(vector<vector<int>> &res,TreeNode *root,int dep) {
        if(!root)
            return;
        if(res.size()==dep)
            res.push_back(vector<int>());
        res[dep].push_back(root->val);
        buildvec(res,root->left,dep+1);
        buildvec(res,root->right,dep+1);
    }
};
