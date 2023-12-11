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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //p and q both in right
        if(root->val < p->val && root->val < q->val ){
            TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }

        //p and q both in left
        if(root->val > p->val && root->val > q->val ){
            TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
            return leftAns;
        }

        //p and q are on the opposite sides, means current node is their common parent
        return root;
    }
};