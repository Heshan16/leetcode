/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

//起先，我是用了一个变量传递引用来表示maxlay,看别人的codes才发现，其实res.size()就是maxlay啊！！其实不需要maxlay的！！so ,it make codes more simple 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recurSideView(root,1,res);
        return res;
    }
    void recurSideView(TreeNode *root,int cur,vector<int> &res) {
        if(!root)
            return;
        if(cur>res.size())
            res.push_back(root->val);
        recurSideView(root->right,cur+1,res);
        recurSideView(root->left,cur+1,res);
    }
};
