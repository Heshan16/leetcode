/*


Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],

   1
    \
     2
    /
   3

return [1,3,2]. 
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
    vector<int> inorderTraversal(TreeNode* root) {
//中序遍历二叉树问题
        vector<int> res;
        recur_visit(res,root);
        return res;
    }
    void recur_visit(vector<int> &vi,TreeNode *root) {
        if(!root)
            return;
        recur_visit(vi,root->left);
        vi.push_back(root->val);
        recur_visit(vi,root->right);
    }
};
