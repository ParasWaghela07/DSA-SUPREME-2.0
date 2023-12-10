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