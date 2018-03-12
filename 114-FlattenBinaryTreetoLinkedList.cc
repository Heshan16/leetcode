//Solution 1,using stack
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode h(0),*pre=&h,*cur;
        stack<TreeNode *> wait;
        if(root)
            wait.push(root);
        while(!wait.empty()) {
            cur=wait.top();
            wait.pop();
            pre->left=NULL;
            pre->right=cur;
            if(cur->right)
                wait.push(cur->right);
            if(cur->left)
                wait.push(cur->left);
            pre=cur;
        }
        pre->left=NULL;
        pre->right=NULL;
    }
}

//Solution 2,using recursion
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        flatten_recur(root);   
    }
    
    TreeNode *flatten_recur(TreeNode *root) {
        if(!root->left && !root->right)
            return root;
        if(!root->left)
            return flatten_recur(root->right);
        if(!root->right){
            root->right=root->left;
            root->left=NULL;
            return flatten_recur(root->right);
        }
            
        TreeNode *tailleft=flatten_recur(root->left);
        TreeNode *tailright=flatten_recur(root->right);
        tailleft->right=root->right;
        root->right=root->left;
        root->left=NULL;
        return tailright;
    }
};

//Solution 3,with o(1) space,o(n) time complexity
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *now=root;
        while(now) {
            if(now->left) {
                TreeNode *left=now->left;
                while(left->right)
                    left=left->right;
                left->right=now->right;
                now->right=now->left;
                now->left=NULL;
            }
            else
                now=now->right;
        }
    }
};
