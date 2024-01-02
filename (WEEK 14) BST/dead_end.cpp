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
