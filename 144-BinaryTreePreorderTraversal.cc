/*
Given a binary tree, return the preorder traversal of its nodes' values.
*/

// Solution 1, using recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root)
            recur_traver(root,result);
        return result;
    }
    void recur_traver(TreeNode *root,vector<int> &res) {
        res.push_back(root->val);
        if(root->left)
            recur_traver(root->left,res);
        if(root->right)
            recur_traver(root->right,res);
    }
};

// Solution 2,using a stack
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> nodes;
        if(root)
            nodes.push(root);
        while(!nodes.empty()) {
            TreeNode *cur=nodes.top();
            res.push_back(cur->val);
            nodes.pop();
            if(cur->right)
                nodes.push(cur->right);
            if(cur->left)
                nodes.push(cur->left);
         }
        return res;
    }
}

// Solution 3,Morris traverser
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur=root;
        vector<int> res;
        while(cur) {
            if(!cur->left) {  //must first meet this node
                res.push_back(cur->val);
                cur=cur->right;
            }
            else {
                TreeNode *pre=cur->left;
                while(pre->right && pre->right!=cur) 
                    pre=pre->right;
                if(pre->right) {
                    pre->right=NULL;
                    cur=cur->right;
                }
                else {
                    res.push_back(cur->val);
                    pre->right=cur;
                    cur=cur->left;
                }
            }
        }
        return res;
    }
};
