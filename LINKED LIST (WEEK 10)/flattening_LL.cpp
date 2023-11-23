
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


