//own solution


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
    void solve(TreeNode* root, int low, int high,int &sum){
        if(root==NULL){
            return;
        }

        if(root->val >= low && root->val<=high){
            sum+=root->val;
        }

        if(root->val > low )
        solve(root->left,low,high,sum);
        if(root->val < high )
        solve(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        solve(root,low,high,sum);

        return sum;
    }
};


//lakshay bhaiya's solution

int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;

        int sum=0;
        bool inRange=false;

        if(root->val >= low && root->val<=high){
            sum+=root->val;
            inRange=true;
        }

        if(inRange){
            sum+=rangeSumBST(root->left,low,high) + rangeSumBST(root->right , low ,high);
        }
        else if(root->val < low ){
            sum+=rangeSumBST(root->right , low ,high);
        }
        else{
            sum+=rangeSumBST(root->left,low,high);
        }

        return sum;

    }