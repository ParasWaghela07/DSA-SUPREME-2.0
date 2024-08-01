//OWN SOLUTION

class Solution {
public:
    void insert(TreeNode* root,int data){
        if(root==NULL) return;

        // if(root->left==NULL && root->right==NULL){
        //     if(root->val>data){
        //         root->left=new TreeNode(data);
        //     }
        //     else{
        //         root->right=new TreeNode(data);
        //     }
        //     return;
        // }
        if(root->val < data && root->right==NULL){
            root->right=new TreeNode(data);
            return;
        }
        else if(root->val > data && root->left==NULL){
            root->left=new TreeNode(data);
            return;
        }
        
        if(root->val > data)
        insert(root->left,data);
        else
        insert(root->right,data);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);

        for(int i=1;i<preorder.size();i++){
            insert(root,preorder[i]);
        }

        return root;
    }
};

//optimized
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
    TreeNode* helper(int &index,vector<int>&preorder,int mini,int maxi){
        if(index<preorder.size() && preorder[index]>mini && preorder[index]<maxi){
            TreeNode* root=new TreeNode(preorder[index++]);

            root->left=helper(index,preorder,mini,root->val);
            root->right=helper(index,preorder,root->val,maxi);

            return root;
        }
        else{
            return NULL;
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        int mini=INT_MIN;
        int maxi=INT_MAX;
        TreeNode* root=helper(index,preorder,INT_MIN,INT_MAX);
        return root;
    }
};

//LAKSHAY BHAIYA'S SOLUTION

TreeNode* build(int &i,int min,int max,vector<int>preorder){
        if(i>=preorder.size()){
            return NULL;
        }
        TreeNode* root=NULL;
        if(preorder[i] > min && preorder[i] < max ){
            root=new TreeNode(preorder[i++]);
            root->left=build(i,min,root->val,preorder);
            root->right=build(i,root->val,max,preorder);
        }

        return root;
    }