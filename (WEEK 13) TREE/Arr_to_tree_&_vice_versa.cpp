    void preorder(Node*root,vector<int>&pre){
        if(!root){
            pre.push_back(-1);
            return;
        }
        
        pre.push_back(root->data);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int>pre;
        preorder(root,pre);
        
        return pre;
    }
    
    //Function to deserialize a list and construct the tree.
    Node* makeTree(vector<int>&A,int &index){
        if(A[index]==-1 || index>=A.size()){
            index++;
            return NULL;
        }
        
        Node*root=new Node(A[index]);
        index++;
        
        root->left=makeTree(A,index);
        root->right=makeTree(A,index);
        
        return root;
    }
    Node * deSerialize(vector<int> &A)
    {
       int index=0;
       return makeTree(A,index);
    }