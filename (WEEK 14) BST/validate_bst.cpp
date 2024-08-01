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
    void helper(TreeNode* root,int &value,bool &flag){
        if(flag){
            if(!root) return;

            helper(root->left,value,flag);

            if(value==1e9 || root->val > value) value=root->val;
            else flag=false;

            helper(root->right,value,flag);
        }
    }
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        int value=1e9;
        helper(root,value,flag);

        return flag;
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
    bool helper(TreeNode* root,long int mini,long int maxi){
        if(!root) return true;

        if(mini<root->val && maxi>root->val) {
            bool leftAns=helper(root->left,mini,root->val);
            bool rightAns=helper(root->right,root->val,maxi);

            return leftAns && rightAns;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        long mini=-2147483649;
        long maxi=2147483648;
        return helper(root,mini,maxi);
    }
};


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