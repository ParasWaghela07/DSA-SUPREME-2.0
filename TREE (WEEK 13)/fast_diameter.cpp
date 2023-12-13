
int Diameter=0;


int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }

    int lefth=height(root->left);
    int righth=height(root->right);

    int curr_diameter=lefth+righth;
    Diameter=max(Diameter,curr_diameter);

    return max(lefth,righth)+1;
}

int maxDiameter(TreeNode* root){
    height(root);

    return Diameter;
}