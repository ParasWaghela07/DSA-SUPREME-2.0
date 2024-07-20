
class Solution {
public:
    int helper(TreeNode* root,bool &flag,bool &goback){
        if(!root) return 0;
        if(goback) return 0;

        int leftHeight=helper(root->left,flag,goback);
        int rightHeight=helper(root->right,flag,goback);

        if(abs(leftHeight-rightHeight)>1){
            flag=false;
            goback=true;
        }

        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        bool goback=false;
        int height=helper(root,flag,goback);

        return flag;
    }
};


class Solution {
public:

    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int diff=abs(leftHeight-rightHeight);

        bool curr_ans=(diff<=1);

        bool left_ans=isBalanced(root->left);
        bool right_ans=isBalanced(root->right);

        if(curr_ans && left_ans && right_ans){
            return true;
        }
        else{
            return false;
        }


    }
};