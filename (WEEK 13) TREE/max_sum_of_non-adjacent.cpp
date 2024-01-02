class Solution{
  public:
    pair<int,int> solve(Node* root){
        if(!root) return {0,0};
        
        auto leftAns=solve(root->left);
        auto rightAns=solve(root->right);
        
        //SUM including current node
        int sum1=root->data + leftAns.second + rightAns.second;
        
        //SUM excluding current node
        int sum2=max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
        
        return {sum1,sum2};
        
        
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        auto ans=solve(root);
        
        return max(ans.first,ans.second);
    }
};