/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        if(root) 
            recur_pathSum(root,sum,res,cur);
        return res;
    }
    void recur_pathSum(TreeNode *root,int sum,vector<vector<int>> &res,vector<int> &cur) {
        cur.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==root->val)
                res.push_back(cur);
        }
        else {
            if(root->left)
                recur_pathSum(root->left,sum-root->val,res,cur);
            if(root->right)
                recur_pathSum(root->right,sum-root->val,res,cur);
        }
        cur.pop_back();
    }
};
