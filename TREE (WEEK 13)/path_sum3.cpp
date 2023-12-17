//OWN SOLUTION
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
 #define ll long long int 
class Solution {
public:

int ans=0;

    void solve(TreeNode* root,int &count,ll sum,int target){
        if(root==NULL){
            return;
        }
        sum=sum+root->val;
        if(sum==target){
            count++;
            
            // sum=root->val;

        }
        // else if(sum>target){
        //     return;
        // }

        solve(root->left,count,sum,target);
        solve(root->right,count,sum,target);
    }

    void helper(TreeNode* root,int &count,ll sum,int targetSum){
        if(root==NULL){
            return;
        }
        solve(root,count,sum,targetSum);
        helper(root->left,count,sum,targetSum);
        helper(root->right,count,sum,targetSum);

    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        ll sum=0;
        helper(root,count,sum,targetSum);
        return count;
    }

    
};












//lakshay bhaiya's solution
void solve(TreeNode* root,long long sum){
        if(root==NULL){
            return;
        }

        if(sum==root->val){
            ans++;
        }
        solve(root->left,sum-root->val);
        solve(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root,long long targetSum){
        if(root){
            solve(root,targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }

