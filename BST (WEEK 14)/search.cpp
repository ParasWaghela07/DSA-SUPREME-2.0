bool isPresent(Node* root,int val){
    if(root==NULL){
        return false;
    }

    if(root->data == val ){
        return true;
    }

    bool leftans=isPresent(root->left,val);
    bool rightans=isPresent(root->right,val);

    return leftans||rightans;
}