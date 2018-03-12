/*


Given a binary tree, return the inorder traversal of its nodes' values.
*/

//Solution 1,using recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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

//Solution 2,using a stack to iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> nodes;
        TreeNode *cur=root;
        while(!nodes.empty() || cur) {
            if(cur) {
                nodes.push(cur);
                cur=cur->left;
            }
            else {
                TreeNode *p=nodes.top();
                nodes.pop();
                res.push_back(p->val);
                cur=p->right;
            }
        }
        return res;
    }
};

//Solution 3,Morris traverser
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur=root;
        vector<int> res;
        while(cur) {
            if(!cur->left) {
                res.push_back(cur->val);
                cur=cur->right;
            }
            else {
                TreeNode *pre=cur->left;
                while(pre->right && pre->right!=cur)
                    pre=pre->right;
                if(pre->right) {
                    pre->right=NULL;
                    res.push_back(cur->val);
                    cur=cur->right;
                }
                else {
                    pre->right=cur;
                    cur=cur->left;
                }
            }
        }
        return res;
    }
};
