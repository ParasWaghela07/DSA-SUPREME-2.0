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

void solve(Node* root, unordered_map<Node*, Node*>& mp, Node*& prev) {
    if (!root) return;

    solve(root->left, mp, prev);
    mp[root] = prev;
    prev = root;
    solve(root->right, mp, prev);
}

Node* findPredecessor(Node* root, Node* p) {
    unordered_map<Node*, Node*> mp;
    Node* prev = NULL;
    solve(root, mp, prev);
    return mp[p];
}