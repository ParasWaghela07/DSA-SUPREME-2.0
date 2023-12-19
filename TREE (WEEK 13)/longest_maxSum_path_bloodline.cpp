class Solution
{
public:
    pair<int,int> Jodi(Node* root,int level){
        if(root==NULL){
            pair<int,int>p;
            p.first=0;
            p.second=INT_MIN;
            
            return p;
        }
        
        pair<int,int> leftAns=Jodi(root->left,level+1);
        pair<int,int> rightAns=Jodi(root->right,level+1);
        
        if(leftAns.second > rightAns.second){
            pair<int,int>p;
            p.first=leftAns.first+root->data;
            
            if(level<leftAns.second)
            p.second=leftAns.second;
            
            else
            p.second=level;
            
            return p;
        }
        else if(leftAns.second<rightAns.second){
            pair<int,int>p;
            p.first=rightAns.first+root->data;
            
            if(level<rightAns.second)
            p.second=rightAns.second;
            
            else
            p.second=level;
            
            return p;
        }
        else{
            pair<int,int>p;
            int element=max(leftAns.first,rightAns.first);
            p.first=element+root->data;
            
            if(level<rightAns.second)
            p.second=rightAns.second;
            
            else
            p.second=level;
            
            return p;
        }
        
    }
    
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int level=1;
        pair<int,int>p=Jodi(root,level);
        
        return p.first;
    }
};