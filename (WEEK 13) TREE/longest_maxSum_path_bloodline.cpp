class Solution
{

//MY SOLUTION
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


//HEET SOLUTION
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    void solve(Node* root,int level,int sum,vector<pair<int,int>>&ans){
if(root==NULL) return;
       sum+=root->data;
       if(!root->left && !root->right){
           pair<int,int>p;
           p.first=sum;
           p.second=level;
           ans.push_back(p);
           return;
       }
       
       solve(root->left,level+1,sum,ans);
       solve(root->right,level+1,sum,ans);
   }

   int sumOfLongRootToLeafPath(Node *root)
    {
        
        vector<pair<int,int>>a ;
        int level = 1;
        int sum = 0;
        solve(root,a,level,sum);
        int ans = INT_MIN;
        int storageAnswer = 0;
        
        for(auto ch:a){
               if(ch.second>storageAnswer){
                   ans = ch.first;
                   storageAnswer=ch.second;
               } 
               else if(ch.second==storageAnswer){
                   ans = max(ans,ch.first);
               }
        }
        return ans ;
        //code here
    }


    
//     int sumOfLongRootToLeafPath(Node *root)
//     {
//         vector<pair<int, int>>ans;
//         int level=1;
//         int sum=0;
        
//         solve(root,level,sum,ans);
//         vector<int>maxLevel;
// int Check=INT_MIN;
// for(int i=0;i<ans.size();i++){

// auto a=ans[i];
// if(a.second>Check)
// Check=a.second;

// }

// int Final=INT_MIN;
// for(int i=0;i<ans.size();i++){

// auto a=ans[i];
// if(a.second==Check)
// if(a.first>Final)
// Final=a.first;

// }

// return Final;

// }

};


//LAKSHAY BHAIYA'S SOLUTION
pair<int,int> height(Node* root){
        if(root==NULL){
            return {0,0}; 
        }
        
        auto leftAns=height(root->left);
        auto rightAns=height(root->right);
        
        int sum=root->data;
        if(leftAns.first == rightAns.first){
            sum+=leftAns.second>rightAns.second?leftAns.second:rightAns.second;
        }
        else if(leftAns.first>rightAns.first){
            sum+=leftAns.second;
        }
        else{
            sum+=rightAns.second;
        }
        
        return {max(leftAns.first,rightAns.first)+1,sum}; 
    }
    
    int sumOfLongRootToLeafPath(Node *root){
        auto h=height(root);
        return h.second;
    }