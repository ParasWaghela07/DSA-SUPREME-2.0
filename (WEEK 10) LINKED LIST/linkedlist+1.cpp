#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(){
        
        this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void printLL(Node* head){

    Node* temp=head;
  
    while(temp!=NULL){
        
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverse(Node* &head){
    Node *prev=NULL;
    Node *curr=head;

    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head=prev;
}

    void InsertAtEnd(Node* &head,Node* &tail,int data){

        if(head==NULL){
            Node* newnode=new Node(data);
            head=newnode;
            tail=newnode;
        }
        else{

        Node* newnode=new Node(data);
        tail->next=newnode;
        tail=newnode;
        }

    }

    void AddOne(Node* &head){
        reverse(head);

        Node* curr=head;
        int carry=1;
        

        while(curr->next!=NULL){
            int digit=(curr->data);

            digit=digit+carry;
            carry=digit/10;

            if(carry!=1){
                curr->data=digit%10;
                break;
            }

            curr->data=digit%10;
        
            curr=curr->next;

        }

        if(carry==1){

        int digit=(curr->data);
            digit=digit+carry;
            carry=digit/10;

        if(carry==1){
           curr->data=digit%10;
           Node *ex=new Node();
           ex->data=1;
           ex->next=NULL;
           curr->next=ex;
        }
        else{
            curr->data=digit%10;
        }

        }

        reverse(head);
        


    }



int main(){
   Node *head=NULL;
   Node *tail=NULL;

//    InsertAtEnd(head,tail,9);
//    InsertAtEnd(head,tail,9);
   InsertAtEnd(head,tail,0);
   InsertAtEnd(head,tail,0);
   InsertAtEnd(head,tail,0);
   printLL(head);

   AddOne(head);
   printLL(head);




}