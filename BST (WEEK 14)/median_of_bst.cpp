//OWN SOLUTION
void inorder(struct Node *root,vector<int>&in ){
    if(!root) return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
float findMedian(struct Node *root)
{
      vector<int>in;
      inorder(root,in);
      
      int n=in.size();
      
      if(n%2==0){
          
          float a=in[(n/2)-1];
          float b=in[(n/2)];
          
          float ans=(a+b)/2;
          
          return ans;
          
      }
      else{
          return in[(n)/2];
      }
}

//LAKSHAY BHAIYA'S SOLUTION //MORRIS TRAVERSAL

int FindNosOfNodes(struct Node* root) {
        int count=0;
        Node* curr=root;

        while(curr){
            //if left is null then visit curr and go right
            if(curr->left==NULL){
                count++;
                curr=curr->right;
            }
            else{
                //find inorder predecessor
                Node* pred=curr->left;
                while(pred->right!=curr && pred->right!=NULL){
                    pred=pred->right;
                }

                //if pred ka right is null of pred, then connect its right to root/curr and move curr on left
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    //left is already visited , go right after visiting curr node and remove right link
                    pred->right=NULL;
                    count++;
                    curr=curr->right;
                }
            }
        }
        return count;
    }
    float findAns(struct Node* root,int n) {
        int i=0;
        int odd1=(n+1)/2; 
        int odd1val=-1;
        int even1=(n/2);
        int even1val=-1;
        int even2=(n/2)+1;
        int even2val=-1;
        
        Node* curr=root;

        while(curr){
            //if left is null then visit curr and go right
            if(curr->left==NULL){
                i++;
                if(i==odd1) odd1val=curr->data;
                if(i==even1) even1val=curr->data;
                if(i==even2) even2val=curr->data;
                curr=curr->right;
            }
            else{
                //find inorder predecessor
                Node* pred=curr->left;
                while(pred->right!=curr && pred->right!=NULL){
                    pred=pred->right;
                }

                //if pred ka right is null of pred, then connect its right to root/curr and move curr on left
                if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    //left is already visited , go right after visiting curr node and remove right link
                    pred->right=NULL;
                    i++;
                    if(i==odd1) odd1val=curr->data;
                    if(i==even1) even1val=curr->data;
                    if(i==even2) even2val=curr->data;
                    curr=curr->right;
                }
            }
        }
        
        float ans=-1;
        if(n%2==0){
            ans=(even1val + even2val) / 2.0;
        }
        else{
            ans=(odd1val);
        }
        
        return ans;
    }
    

    float findMedian(struct Node* root){
        int n=FindNosOfNodes(root);
        return findAns(root,n);
    }


