class Solution {
public:

//SOLUTION 1
    int maxDepth(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }

        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);

        return max(leftHeight,rightHeight) + 1;

    }
};


//SOLUTION 2
if(root==NULL){
            return 0;
        }
        int height=1;

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();

            if(front==NULL){
                if(!q.empty()){
                height++;
                q.push(NULL);
                }
            }
            else{
                if(front->left!=NULL)
                q.push(front->left);
                if(front->right!=NULL)
                q.push(front->right);
            }
        }

        return height;