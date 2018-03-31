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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return NULL;
        return buildTree_recur(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode *buildTree_recur(vector<int>& preorder, vector<int>& inorder,int preb,int pree,int inb,int ine) {
        TreeNode *cur=new TreeNode(preorder[preb]);
        int i;
        for(i=inb;i<=ine && inorder[i]!=preorder[preb];i++)
            ;
        if(i>inb)
            cur->left=buildTree_recur(preorder,inorder,preb+1,preb+i-inb,inb,i-1);
        if(i<ine)
            cur->right=buildTree_recur(preorder,inorder,preb+i-inb+1,pree,i+1,ine);
        return cur;
    }
};
