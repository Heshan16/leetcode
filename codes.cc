
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> res;
        res.push_back(nullptr);
        for(int i=1;i<=n;i++) {
            vector<TreeNode *> temp;
            int sz=res.size();
            for(int j=0;j<sz;j++) {
                TreeNode *newsub=CloneTree(res[j]);
				TreeNode *newTree=new TreeNode(i);
				newTree->left=newsub;
				temp.push_back(newTree);
				TreeNode *oldT=res[j],subr=oldT;
				while(subr) {
						TreeNode *rchild=subr->right,newnode=new TreeNode(i);
						newnode->left=rchild;
						subr->right=newnode;
						temp.push_back(CloneTree(oldT));
						subr->right=rchild;
						subr=subr->right;
				}
            }
			res=std::move(temp);
        }
		return res;
    }
    TreeNode *CloneTree(TreeNode *root) {
        TreeNode *newR=new TreeNode(root->val);
        if(root->left)
            newR->left=CloneTree(root->left);
        if(root->right)
            newR->right=CloneTree(root->right);
        return newR;
    }
};
