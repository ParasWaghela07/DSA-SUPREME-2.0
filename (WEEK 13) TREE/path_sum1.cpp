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

    bool solve(TreeNode* root, int targetSum,int sum){
        if(root==NULL) return false;

        sum+=root->val;

        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                return true;
            }
            else{
                return false;
            }
        }

        bool leftans=solve(root->left,targetSum,sum);
        bool rightans=solve(root->right,targetSum,sum);

        return leftans || rightans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=solve(root,targetSum,sum);

        return ans;
    }
};


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
    void helper(TreeNode* root,int target,bool &ans){
        if(!root) return;
        target=target-root->val;

        if(!root->left && !root->right && target==0){
            ans=true;
            return;
        }

            helper(root->left,target,ans);
            helper(root->right,target,ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        helper(root,targetSum,ans);

        return ans;
    }
};
