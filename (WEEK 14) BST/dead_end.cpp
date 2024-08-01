//MINE
class Solution{
  public:
    void helper(Node*root,bool &ans,int mini,int maxi){
        if(!ans){
            if(!root) return;
            if(!root->left && !root->right){
                if(root->data-mini==1 && maxi-root->data==1){
                    ans=true;
                }
            }
            
            helper(root->left,ans,mini,root->data);
            helper(root->right,ans,root->data,maxi);
        }
    }
    bool isDeadEnd(Node *root)
    {
        bool ans=false;
        helper(root,ans,0,10002);
        return ans;
    }
};

class Solution{
  public:
    bool helper(Node*root,int mini,int maxi){
        if(!root) return false;
        if(!root->left && !root->right){
            if(root->data-mini==1 && maxi-root->data==1){
                return true;
            }
        }
        bool leftAns=helper(root->left,mini,root->data);
        bool rightAns=helper(root->right,root->data,maxi);
        
        return leftAns||rightAns;
    }
    bool isDeadEnd(Node *root)
    {
        return helper(root,0,10002);
    }
};

//LAKSHAY BHAIYA'S SOLU
class Solution{
  public:
    map<int,bool>mp;
    bool flag=false;
    
    void solve(Node* root){
        if(flag==true) return;
        if(root==NULL){
            return;
        }
        mp[root->data]=true;
       
        if(root->left==NULL && root->right==NULL){
           
            int element=root->data;
            int prev=element-1==0?element:element-1;
            int next=element+1;
            
            if(mp.find(prev)!=mp.end() && mp.find(next)!=mp.end()){
                flag=true;
                return;
            }
        }
        
        solve(root->left);
        solve(root->right);
        
    }
    bool isDeadEnd(Node *root)
    {
        if(root==NULL){
            return true;
        }
        
        solve(root);
        return flag;
        
    }
};

//METHOD 2
class Solution {
public:
    bool isDeadEnd(Node* root) {
        return isDeadEndHelper(root, 0, INT_MAX);
    }
    
    bool isDeadEndHelper(Node* node, int minVal, int maxVal) {
        if (node == nullptr) {
            return false; // Base case: Node doesn't exist, no dead end found
        }
        
        // Check if the current node leads to a dead end
        if (minVal == maxVal) {
            return true; // Dead end found
        }
        
        // Traverse left subtree with updated min and max values
        bool leftDeadEnd = isDeadEndHelper(node->left, minVal, node->data - 1);
        
        // Traverse right subtree with updated min and max values
        bool rightDeadEnd = isDeadEndHelper(node->right, node->data + 1, maxVal);
        
        // If either subtree has a dead end, return true
        if (leftDeadEnd || rightDeadEnd) {
            return true;
        }
        
        return false; // No dead end found
    }
};
