//MY SOLUTION


int getlen(SinglyLinkedListNode* llist){
     SinglyLinkedListNode* temp=llist;
     int count=0;
     
     while(temp!=NULL){
         count++;
         temp=temp->next;
     }
     
     return count;
 }

int getNode(SinglyLinkedListNode* llist/*head*/, int positionFromTail) {
    
    int posi=getlen(llist)-positionFromTail;
    SinglyLinkedListNode* temp=llist;
    
    while(posi!=1){
        temp=temp->next;
        posi--;
    }
    
    return temp->data;
}




//LAKSHAY BHAIYA SOLUTION

void fun(SinglyLinkedListNode* llist/*head*/, int &positionFromTail , int &ans){
    if(head==NULL){   //terminating condition when head reaches null
        return;
    }

        fun(llist->next,positionFromTail,ans); //recursive call to push head to null

        //this line means last recursive call is returned from base condition, so head will be on last element of list
        //use backtrack to find element at nth position

        if(positionFromTail==0){
            ans=head->data;
        }
        positionFromTail--;

}


int getNode(SinglyLinkedListNode* llist/*head*/, int positionFromTail) {
    
    int ans=-1;
    fun(llist,positionFromTail,ans);

    return ans;
}
