//BRUTE FORCE O(N*N)
int count=0;
    void bst2(Node* root,int target){
        if(root==NULL){
            return;
        }
        if(root->data==target){
            count++;
        }
        if(root->data > target ){
            bst2(root->left,target);
        }
        else{
            bst2(root->right,target);
        }
    }
    void bst1(Node* root1,Node* root2,int x){
        if(root1==NULL){
            return;
        }
        bst2(root2,x-root1->data);
        bst1(root1->left,root2,x);
        bst1(root1->right,root2,x);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        bst1(root1,root2,x);
        return count;
    }


//MY SOLUTION 

void inorder(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>v1;
        vector<int>v2;
        inorder(root1,v1);
        inorder(root2,v2);
        
        int i=0;
        int j=v2.size()-1;
        int count=0;
        
        while(i<v1.size() && j>=0){
            if(v1[i]+v2[j]==x){
                count++;
                i++;
                j--;
                
            }
            else if(v1[i]+v2[j]>x){
                j--;
            }
            else{
                i++;
            }
        }
        
        return count;
    }

    //LAKSHAY BHAIYA'S SOLUTION

     int countPairs(Node* root1, Node* root2, int x){
     int count=0;
     stack<Node*>s1,s2;
     Node* a=root1;
     Node* b=root2;
     
     while(1){
         while(a){
             s1.push(a);
             a=a->left;
         }
         while(b){
             s2.push(b);
             b=b->right;
         }
         if(s1.empty() || s2.empty()){
             break;
         }
         
         auto atop=s1.top();
         auto btop=s2.top();
         
         int sum=atop->data + btop->data;
         
         if(sum==x){
             count++;
             a=atop->right;
             b=btop->left;
             s1.pop();
             s2.pop();
         }
         else if(sum<x){
             s1.pop();
             a=atop->right;
         }
         else{
             s2.pop();
             b=btop->left;
         }
     }
     
     return count;
 }
