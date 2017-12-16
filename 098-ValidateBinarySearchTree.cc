/*
 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

    2
   / \
  1   3

Binary tree [2,1,3], return true.

Example 2:

    1
   / \
  2   3

Binary tree [1,2,3], return false. 
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
    bool isValidBST(TreeNode* root) {
        int min,max;
        if(!root)
            return true;
        return recur_validBST(root,min,max);
    }
    bool recur_validBST(TreeNode *root,int &min,int &max) {
        int max1,min1;
        min=max=root->val;
        if((!root->left || (recur_validBST(root->left,min,max1) && max1<root->val))
           && (!root->right || (recur_validBST(root->right,min1,max) && min1>root->val))) {
            return true;
        }
        return false;
    }
};
