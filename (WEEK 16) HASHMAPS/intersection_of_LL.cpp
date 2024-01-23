Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_map<int,int>mp;
        Node* temp=head2;
        while(temp){
            mp[temp->data]++;
            temp=temp->next;
        }
        temp=head1;
        Node* newHead=0;
        Node* curr=0;
        while(temp){
            if(mp.find(temp->data)!=mp.end()){

                if(newHead==0){
                    newHead=temp;
                    curr=temp;
                }
                else if(mp[temp->data]>0){
                    mp[temp->data]--; // to handle duplicate number occurace edge case
                    curr->next=temp;
                    curr=temp;
                }
            }
            temp=temp->next;
        }
        
        curr->next=0;
        
        return newHead;
        
    }