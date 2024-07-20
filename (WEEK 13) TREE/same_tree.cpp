 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }

        if(p!=NULL && q!=NULL){
            return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }

        return false;
    }

    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode*root,vector<int>&v){
        if(!root){
            v.push_back(1e9);
            return;
        }
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>pre1;
        vector<int>pre2;

        preorder(p,pre1);
        preorder(q,pre2);

        if(pre1.size()!=pre2.size()) return false;

        for(int i=0;i<pre1.size();i++){
            if(pre1[i]!=pre2[i]) return false;
        }

        return true;
    }
};