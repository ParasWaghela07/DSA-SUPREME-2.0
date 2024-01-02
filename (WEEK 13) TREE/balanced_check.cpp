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
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int diff=abs(leftHeight-rightHeight);

        bool curr_ans=(diff<=1);

        bool left_ans=isBalanced(root->left);
        bool right_ans=isBalanced(root->right);

        if(curr_ans && left_ans && right_ans){
            return true;
        }
        else{
            return false;
        }


    }
};