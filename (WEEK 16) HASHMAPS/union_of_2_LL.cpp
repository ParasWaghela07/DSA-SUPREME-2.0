  //LAKSHAY MAP BEST
    map<int,Node*>mp;
         Node* temp=head1;
         while(temp){
             mp[temp->data]=temp;
             temp=temp->next;
         }
         temp=head2;
         while(temp){
             mp[temp->data]=temp;
             temp=temp->next;
         }
         
         Node* newHead=0;
         temp=0;
         
         //  for(auto it=mp.begin();it!=mp.end();it++){ ==== it->first && it->second
        for(auto it:mp){
             if(newHead==0){
                 newHead=it.second;
                 temp=it.second;
             }
             else{
                 temp->next=it.second;
                 temp=temp->next;
             }
         }
         
         temp->next=0;
         
         return newHead;
    

    
class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        vector<int>v;
        Node*temp=head1;
        while(temp){
            v.push_back(temp->data);
            temp=temp->next;
        }
       
        temp=head2;
        while(temp){
            v.push_back(temp->data);
            temp=temp->next;
        }
       
        sort(v.begin(),v.end());
       
        Node* newHead=new Node(v[0]);
        temp=newHead;
       
        for(int i=1;i<v.size();i++){
            if(v[i]==temp->data) continue;
            Node* newNode=new Node(v[i]);
            temp->next=newNode;
            temp=newNode;
        }
       
        return newHead;
    }
};


//own
struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int>s;
        Node* temp=head1;
        while(temp!=NULL){
            s.insert(temp->data);
            temp=temp->next;
        }
        temp=head2;
        while(temp!=NULL){
            s.insert(temp->data);
            temp=temp->next;
        }
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        for(auto it:s){
            Node* temp=new Node(it);
            tail->next=temp;
            tail=temp;
        }
        
        return dummy->next;
    }

  