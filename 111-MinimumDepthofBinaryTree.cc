/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
//dfs solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left)
            return minDepth(root->right)+1;
        if(!root->right)
            return minDepth(root->left)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};

//bfs solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode *> tq;
        tq.push(root);
        int deep=0;
        while(!tq.empty()) {
            deep++;
            int sz=tq.size();
            for(int i=0;i<sz;i++) {
                TreeNode *cur=tq.front();
                tq.pop();
                if(!cur->left && !cur->right)
                    return deep;
                if(cur->left)
                    tq.push(cur->left);
                if(cur->right)
                    tq.push(cur->right);
            }
        }
        return -1;
    }
};
