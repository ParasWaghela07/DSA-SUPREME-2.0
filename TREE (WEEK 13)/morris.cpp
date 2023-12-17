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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans; 
        TreeNode* curr=root;

        while(curr){
            //if left is null then visit curr and go right
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                //find inorder predecessor
                TreeNode* pred=curr->left;
                while(pred->right!=curr && pred->right!=NULL){
                    pred=pred->right;
                }

                //if pred ka right is null of pred, then connect its right to root/curr and move curr on left
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    //left is already visited , go right after visiting curr node and remove right link
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};