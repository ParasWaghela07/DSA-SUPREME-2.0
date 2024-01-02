#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    Node(){
        this->next=NULL;
        this->prev=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void printDLL(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlen(Node* &head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void InsertAtHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newnode=new Node(data);
        head=newnode;
        tail=newnode;
    }
    else{
        Node* newnode=new Node(data);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newnode=new Node(data);
        head=newnode;
        tail=newnode;
    }
    else {
        Node* newnode=new Node(data);
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}

void InsertAtPosition(Node* &head,Node* &tail,int data,int posi){

    if(posi==1){
        InsertAtHead(head,tail,data);
    }
    else if(posi==getlen(head)+1){
        InsertAtTail(head,tail,data);
    }
    else{
        Node* newnode=new Node(data);

        Node* prevN=NULL;
        Node* curr=head;

        while(posi!=1){
            prevN=curr;
            curr=curr->next;
            posi--;
        }

        newnode->prev=prevN;
        prevN->next=newnode;

        newnode->next=curr;
        curr->prev=newnode;
    }
}

void DeleteNode(Node* &head,Node* &tail,int posi){
    if(head==NULL){
        cout<<"Cannot delete , coz DLL is already Empty"<<endl;
        tail=NULL;
    }
    else if(head==tail){
        delete head;
        head=NULL;
        tail=NULL;
    }
    else if(posi==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;

        delete temp;

    }
    else if(posi==getlen(head)){
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;

        delete temp;
    }
    else{
        Node* prevN=NULL;
        Node* currN=head;

        while(posi!=1){
            prevN=currN;
            currN=currN->next;
            posi--;
        }

        Node* nextN=currN->next;

        prevN->next=nextN;
        currN->prev=NULL;
        currN->next=NULL;
        nextN->prev=prevN;

        delete currN;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    // InsertAtHead(head,tail,5);
    // InsertAtHead(head,tail,4);
    // InsertAtHead(head,tail,3);

    // InsertAtTail(head,tail,10);
    // InsertAtTail(head,tail,11);

    // InsertAtPosition(head,tail,69,4);

    InsertAtHead(head,tail,1);
    InsertAtHead(head,tail,2);
    InsertAtHead(head,tail,3);
    InsertAtHead(head,tail,4);
    InsertAtHead(head,tail,5);

    DeleteNode(head,tail,3);
    


    printDLL(head);

    
}