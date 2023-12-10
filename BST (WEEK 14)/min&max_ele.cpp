void FindMinimum(Node* root){
    if(root==NULL){
        return;
    }
    else if(root->left ==NULL && root->right==NULL ){
        cout<<root->data<<endl;
    }
    else{
        FindMinimum(root->left);
    }
}

Node* minValue(Node* root) {
	if(root == NULL) {
		cout << "NO MIN VALUE" << endl;
		return NULL; 
	}
	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}


void FindMaximum(Node* root){
    if(root==NULL){
        return;
    }
    else if(root->left ==NULL && root->right==NULL ){
        cout<<root->data<<endl;
    }
    else{
        FindMaximum(root->right);
    }
}

Node* maxValue(Node* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	Node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}