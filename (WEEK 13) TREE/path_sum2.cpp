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
 *//**
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
    void helper(TreeNode* root,int targetSum,vector<int>&temp,vector<vector<int>>&ans){
        if(!root) return;
        targetSum=targetSum-root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right && targetSum==0){
            ans.push_back(temp);
        }

        helper(root->left,targetSum,temp,ans);
        helper(root->right,targetSum,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;

        helper(root,targetSum,temp,ans);

        return ans;
    }
};


class Solution {
public:
    void solve(TreeNode* root,int targetSum,int sum,vector<vector<int>>&ans,vector<int>temp){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);

        if(root->left ==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
            }
        }

        solve(root->left,targetSum,sum,ans,temp);
        solve(root->right,targetSum,sum,ans,temp);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;

        solve(root,targetSum,sum,ans,temp);

        return ans;
    }
};