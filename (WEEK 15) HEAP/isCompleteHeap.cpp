class Solution {
  public:
  bool isCBT(Node* root,int i,int &n){ //initially i=1, in heap indexing starts from 1 for simplicity , n is total no of ndoes in btree
    if(root==NULL){
        return true;
    }
    if(i>n){
        return false;
    }

    return isCBT(root->left,2*i,n) && isCBT(root->right.2*i + 1 , n);

  }
  bool isComplete(Node* root){
       bool flag=false;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            Node* temp=q.front();
            q.pop();

            if(flag && temp!=NULL){
                return false;
            }
            else if(temp){
            q.push(temp->left);
            q.push(temp->right);
            }
            else{
                flag=true;
            }

        }
        return true;
  }
    bool isHeap(struct Node* tree) {
        if(!isComplete(tree)){
            return false;
        }
       if(tree==NULL){
           return true;
       }
       
       bool leftAns=isHeap(tree->left);
       bool rightAns=isHeap(tree->right);
       
       bool curr=true;
       if(tree->left &&  tree->data < tree->left->data){
           curr=false;
       }
       if(tree->right && tree->data < tree->right->data){
           curr=false;
       }
       
       return (curr && leftAns && rightAns);
    }
};