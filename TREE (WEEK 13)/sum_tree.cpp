//MY SOLUTION

class Solution {
public:
    int toSumTree(Node *&root) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = toSumTree(root->left);
        int rightSum = toSumTree(root->right);

        int oldValue = root->data;
        root->data = leftSum + rightSum;

        return leftSum + rightSum + oldValue;
    }

    void convertToSumTree(Node *&root) {
        if (root == NULL) {
            return;
        }

        // If it's a leaf node, update its value to 0
        if (root->left == NULL && root->right == NULL) {
            root->data = 0;
            return;
        }

        // Calculate the sum for the current node
        int sum = toSumTree(root);

        // Recursively convert left and right subtrees
        convertToSumTree(root->left);
        convertToSumTree(root->right);
    }
};

// class Solution {
//   public:
  
//     // Convert a given tree to a tree where every node contains sum of values of
//     // nodes in left and right subtrees in the original tree
//     int getSum(Node* root){
//         if(root==NULL){
//             return 0;
//         }
        
//         int leftAns=getSum(root->left);
//         int rightAns=getSum(root->right);
        
//         return leftAns+rightAns+root->data;
        
//     }
//     void toSumTree(Node *&root)
//     {
//         if(root==NULL){
//             return;
//         }
//         if(root->left==NULL && root->right==NULL){
//             root->data=0;
//             return;
//         }
//         root->data=getSum(root)-root->data;
//         toSumTree(root->left);
//         toSumTree(root->right);
//     }
// };


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