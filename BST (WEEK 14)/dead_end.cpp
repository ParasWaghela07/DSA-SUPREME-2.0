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

//OWN BUT WRONG
class Solution{
  public:
    map<int,bool>mp;
    bool flag=false;
    
    void solve(Node* root){
        if(root==NULL){
            return;
        }
        mp[root->data]=true;
       
        if(root->left==NULL && root->right==NULL){
            if(root->data==1){
                flag=true;
                return;
            }
            int element=root->data;
            int prev=element-1;
            int next=element+1;
            
            if(mp[prev]==true && mp[next]==true){
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
        if(root->data==1){
            return false;
        }
        solve(root);
        return flag;
        
    }
};