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

     bool Mirror(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }

        if(p!=NULL && q!=NULL){
            return (p->val==q->val) && Mirror(p->left,q->right) && Mirror(p->right,q->left);
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return Mirror(root->left,root->right);
    }
};