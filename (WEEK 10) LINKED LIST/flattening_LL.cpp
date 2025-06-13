
5->10->15->20->NULL             5
|  |   |   |                    |
12 35  43  56             ===>  10
|  |   |   |                    |
23 44  49  69                   12
                                |
                                15
                                |
                                23
                                |
                                20
                                |
                                35
                                |
                                43
                                |
                                44
                                |
                                49
                                |
                                56
                                |
                                69
                                |
                                NULL
                

class Solution {
  public:
    Node* merge(Node*h1,Node*h2){
        Node*dummy=new Node(-1);
        Node*x=dummy;
        
        while(h1 && h2){
            if(h1->data <= h2->data){
                x->bottom=h1;
                x=h1;
                h1=h1->bottom;
            }
            else{
                x->bottom=h2;
                x=h2;
                h2=h2->bottom;
            }
        }
        
        while(h1){
            x->bottom=h1;
            x=h1;
            h1=h1->bottom;
        }
        
        while(h2){
                 x->bottom=h2;
                x=h2;
                h2=h2->bottom;
        }
        
        return dummy->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(!root || !root->next) return root;
        
        Node*h1=root;
        Node*h2=root->next;
        
        while(h1 && h2){
            Node* merged=merge(h1,h2);
            h1=merged;
            h2=h2->next;
        }
        
        return root;
    }
};

Node* merge(Node* a, Node* b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        
        Node* ans=NULL;
        
        if(a->data < b->data){
            ans=a;
            a->bottom=merge(a->bottom,b);
        }
        else{
            ans=b;
            b->bottom=merge(a,b->bottom);
        }
        
        return ans;
    }
Node *flatten(Node *root)
{
   if(root==NULL){
       return root;
   }
   
   Node* ansHead=merge(root,flatten(root->next));
   return ansHead;
}




----------- ITERATIVE -------------

Node* merge(Node* list1,Node* list2){
    if(!list1 && !list2) return NULL;
    if(!list1) return list2;
    if(!list2) return list1;

    
    Node* dummy=new Node(-1);
    Node* x=dummy;
    while(list1 && list2){
        if(list1->data <= list2->data){
            x->bottom=list1;
            x=list1;
            list1=list1->bottom;
        }
        else{
            x->bottom=list2;
            x=list2;
            list2=list2->bottom;
        }
    }
    
    while(list1){
        x->bottom=list1;
        x=list1;
        list1=list1->bottom;
    }
    
    while(list2){
        x->bottom=list2;
        x=list2;
        list2=list2->bottom;
    }
    
    return dummy->bottom;
}
Node *flatten(Node *root)
{
    Node* list1=root;
    Node* list2=root->next;
    
    
    while(list2){
        Node* nxt=list2->next;
        
        list2->next=NULL;
        list1->next=NULL;
        
        Node* mergedPrevNode=merge(list1,list2);
        list1=mergedPrevNode;
        list2=nxt;
    }
    
    return list1;
}
