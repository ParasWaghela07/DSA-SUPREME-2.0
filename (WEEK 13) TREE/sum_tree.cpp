//MY SOLUTION
class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int makeSumTree(Node* &node){
        if(!node) return 0;
        
        int leftSum=makeSumTree(node->left);
        int rightSum=makeSumTree(node->right);
        int currData=node->data;
        
        node->data=leftSum+rightSum;
        
        return currData+leftSum+rightSum;
    }
    void toSumTree(Node *node)
    {
     makeSumTree(node);   
    }
};


//LAKSHAY BHAIYA'S SOLUTION
class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node* root){
        if(root==NULL){
            return 0;
        }
        if(!root->left && !root->right){
            int temp=root->data;
            root->data=0;
            return temp;
        }

        int lsum=sum(root->left);
        int rsum=sum(root->right);

        int temp=root->data;
        root->data=lsum+rsum;

        return root->data + temp;
        
    }
    void toSumTree(Node *root)
    {
        sum(root);
    }
};