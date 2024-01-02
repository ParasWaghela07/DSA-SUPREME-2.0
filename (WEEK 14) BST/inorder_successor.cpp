class Solution{
  public:
   Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(root==NULL) return NULL;
        
        vector<Node*>v;
        inorder(root,v);
        
        for(int i=0;i<v.size()-1;i++){
            if(v[i]->data==x->data){
                return v[i+1];
            }
        }
        
        return NULL;
        
        
    }

    //BETTER SOLU
    
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(root==NULL) return NULL;
        
        Node* ans=NULL;
        
        while(root){
            if(root->data<=x->data){
                root=root->right;
            }
            else {
                ans=root;
                root=root->left;
            }
        }
        return ans;
    }
};