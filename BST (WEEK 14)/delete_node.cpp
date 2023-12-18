//BABBAR BHAIYA'S SOLUTION

Node* deleteNode(Node* root,int target){
    if(root==NULL){
        return NULL;
    }

    if(root->data==target){
        //case 1
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node* child=root->right;
            delete root;
            return  child;
        }
        else if(root->right==NULL && root->left!=NULL){
            Node* child=root->left;
            delete root;
            return  child;
        }
        else{
            Node* leftMax=minValue(root->left);
            root->data=leftMax->data;

            root->left=deleteNode(root->left,leftMax->data);
            return root;

        }
    }
    else if(root->data>target){
        root->left=deleteNode(root->left,target);
    }
    else{
        root->right=deleteNode(root->right,target);
    }

    return root;
}

//LAKSHAY BHAIYA'S SOLUTION
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(!root->left){
                TreeNode* temp=root;
                root=root->right;
                delete temp;

                return root;
            }
            else if(!root->right){
                TreeNode* temp=root;
                root=root->left;
                delete temp;

                return root;
            }
            else{
                TreeNode* rscan=root->right;

                while(rscan->left){
                    rscan=rscan->left;
                }

                rscan->left=root->left;
                auto temp=root;
                root=root->right;
                delete temp;

                return root;
            }
        }

        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            root->left=deleteNode(root->left,key);
        }

        return root;
    }
};

