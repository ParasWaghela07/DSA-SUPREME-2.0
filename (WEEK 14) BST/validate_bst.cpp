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

    bool solve(TreeNode* root,long int lob,long int upb ){
        if(root==NULL){
            return true;
        }

        bool curr=false;

        if(root->val > lob && root->val < upb){
            curr=true;
        }

        bool leftAns=solve(root->left,lob,root->val);
        bool rightAns=solve(root->right,root->val,upb);

        if(curr && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        bool ans=solve(root,-21474836480,21474836470);

        return ans;
    }
};