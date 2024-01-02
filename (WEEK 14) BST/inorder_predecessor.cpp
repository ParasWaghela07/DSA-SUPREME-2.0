Node* findPredecessor(Node* root, Node* p) {
    if(root==NULL){
		return NULL;
	}
	Node* ans=NULL;
	while(root){
		if(root->data>=p->data){
			root=root->left;
		}
		else{
			ans=root;
			root=root->right;
		}
	}
	
	return ans;
}