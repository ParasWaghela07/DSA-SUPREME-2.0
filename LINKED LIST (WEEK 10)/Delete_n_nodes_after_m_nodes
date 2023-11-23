//MY SOLUTION

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
       if(head==NULL){
           return ;
       }
       
       struct Node *temp=head;
       struct Node *prev=NULL;
       
       int m1=M;
       int n1=N;
       
       
       
       while(temp!=NULL){
           
           if(m1>0){
               prev=temp;
               temp=temp->next;
               m1--;
           }
           else{
               
               while(n1>0){
                   if(temp==NULL){
                       break;
                   }
                   struct Node *target=temp;
                   temp=temp->next;
                   prev->next=target->next;
                   target->next=NULL;
                   delete target;
                   n1--;
               }
               
               m1=M;
               n1=N;
               
           }
       }
    }
};



//LAKSHAY BHAIYA SOLUTION

class solution{
    public:
    void linkdelete(struct Node *head,int M,int N){

        if(!head)  //no elements check
        return ;

        Node *it=head; //iterator

        for(int i=0;i<M-1;i++){
            if(!it) return; //if M nodes are NA
            it=it->next;  //going till 1 before node which is going to be deleted
        }

        if(!it)return; //if it still in range

        Node *MthNode=it;
        it=Mthnode->next; //it is on the node which is going to be deleted

        for(int i=0;i<N;i++){
            if(!it) break ; //In range check

            Node *temp=it->next; //temp on next element of deleted node to keep track
            delete it;
            it=temp;//again it on next element
        }

        Mthnode->next=it;//mth node connection with the next node after deleting N nodes

        linkdelete(it,M,N); //recursive call for remaining list
    }
};