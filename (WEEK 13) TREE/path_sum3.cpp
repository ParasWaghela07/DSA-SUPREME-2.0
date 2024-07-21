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
    int ans=0;
    void findSum(TreeNode* root,long int sum,int &target){
        if(!root) return;
        sum+=root->val;

        if(sum==target) ans++;

        findSum(root->left,sum,target);
        findSum(root->right,sum,target);

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        findSum(root,0,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);

        return ans;
    }
};