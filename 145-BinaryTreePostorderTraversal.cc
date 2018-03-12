/*
Given a binary tree, return the postorder traversal of its nodes' values.
*/
//Solution 1,using recursion
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder_recur(root,res);
        return res;
    }
    
    void postorder_recur(TreeNode *root,vector<int> &res) {
        if(root) {
            postorder_recur(root->left,res);
            postorder_recur(root->right,res);
            res.push_back(root->val);
        }
    }
};



//Solution 2,with a stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> nodes;
        if(root)
            nodes.push(root);
        while(!nodes.empty()) {
            TreeNode *cur=nodes.top();
            nodes.pop();
            res.push_back(cur->val);
            if(cur->left)
                nodes.push(cur->left);
            if(cur->right)
                nodes.push(cur->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//solution 2-1,with a stack ,another idea
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> nodes;
        if(root)
            nodes.push(root);
        TreeNode *lastnode=root,*cur;
        //make lastnode root not null,only to make it true for 1-child root   
        while(!nodes.empty()) {
            cur=nodes.top();
            if((!cur->left && !cur->right) || (lastnode==cur->left || lastnode==cur->right)) {
                res.push_back(cur->val);
                nodes.pop();
                lastnode=cur;
            }
            else {
                if(cur->right)
                    nodes.push(cur->right);
                if(cur->left)
                    nodes.push(cur->left);
            }
        }
        return res;
    }
};

//Solution 3
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode head(0),*cur=&head;
        head.left=root;
        while(cur) {
            if(cur->left) {
                TreeNode *pre=cur->left;
                while(pre->right && pre->right!=cur)
                    pre=pre->right;
                if(!pre->right) {
                    pre->right=cur;
                    cur=cur->left;
                }
                else {
                    reverse_node(cur->left,pre->right,res);
                    pre->right=NULL;
                    cur=cur->right;
                }
            }
            else 
                cur=cur->right;
        }
        return res;
    }
    
    void reverse_node(TreeNode *cur,TreeNode *pre,vector<int> &res) {
        int sz=res.size();
        while(cur!=pre) {
            res.push_back(cur->val);
            cur=cur->right;
        }
        reverse(res.begin()+sz,res.end());
    }
}
