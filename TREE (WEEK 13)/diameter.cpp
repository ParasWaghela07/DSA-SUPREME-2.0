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

    int height(TreeNode* root){
        if(root==NULL){
            return NULL;
        }

        int leftAns=height(root->left);
        int rightAns=height(root->right);

        return max(leftAns,rightAns)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        int opt1=diameterOfBinaryTree(root->left);
        int opt2=diameterOfBinaryTree(root->right);
        int opt3=height(root->left)+height(root->right);

        return max(opt1,max(opt2,opt3));
    }
};