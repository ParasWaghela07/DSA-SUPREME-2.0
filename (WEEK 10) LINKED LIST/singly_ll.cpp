#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node*next;

    Node(){
        // cout<<"i am default ctor"<<endl;
        this->next=NULL;
    } 

    Node(int data){
        // cout<<"i am para ctor"<<endl;

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

    int getlength(Node* head){
        Node* temp=head;
        int count=0;

        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        

        return count;
    }

    void InsertAtBegin(Node* &head,Node* &tail,int data){

        if(head==NULL){
            Node* newnode=new Node(data);
            head=newnode;
            tail=newnode;
        }
        else{

        Node* newnode=new Node(data);
        newnode->next=head;
        head=newnode;
        }

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

    void createTail (Node* head,Node* tail){
        Node*temp=new Node();

        while(temp->next!=NULL){
            temp=temp->next;
        }

        tail=temp;
    }

    void InsertAtMid(Node* &head,Node* &tail,int data,int posi){

       if(posi<=1){
            InsertAtBegin(head,tail,data);
        }
        else if(posi>getlength(head)){
            InsertAtEnd(head,tail,data);
        }
        else{

             Node* newnode=new Node(data);
            Node*prev=NULL;
            Node*curr=head;

            while(posi!=1){
                prev=curr;
                curr=curr->next;
                posi--;
            }
           
            prev->next=newnode;
            newnode->next=curr;

        }

        
    }


    void InsertAtMid2(Node* &head,Node* &tail,int data,int posi){

         if(posi<=1){
            InsertAtBegin(head,tail,data);
        }
        else if(posi>getlength(head)){
            InsertAtEnd(head,tail,data);
        }
        else{

            Node* newnode=new Node(data);
            Node* prev=head;

            while(posi!=2){
                prev=prev->next;
                posi--;
            }
            
            newnode->next=prev->next;
            prev->next=newnode;
        }

    }


    void deleteNode(Node* &head,Node* &tail,int posi){

        int len=getlength(head);

        if(head==NULL){
            cout<<"Cannot delete , coz linked list is empty already"<<endl;
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
            delete temp;
        }
        else if(posi==len){
            Node* prev=head;

            while(prev->next!=tail){
                prev=prev->next;
            }

            prev->next=NULL;
            delete tail;
            tail=prev;
        }
        else{
            Node* prev=NULL;
            Node* curr=head;

            while(posi!=1){
                prev=curr;
                curr=curr->next;
                posi--;
            }

            prev->next=curr->next;
            curr->next=NULL;

            delete curr;
        }
    }





int main(){
    
    // Node* ob1=new Node(10);
    // Node* ob2=new Node(20);
    // Node* ob3=new Node(30);           //creating nodes
    // Node* ob4=new Node(40);

    // ob1->next=ob2;              //linking them
    // ob2->next=ob3;
    // ob3->next=ob4;

    // Node* head=ob1;     //head pointer creation
    // Node* tail=ob4;
    // // printLL(head);
    // // cout<<"Total Nodes are : "<<getlength(head)<<endl;
    // InsertAtBegin(head,tail,99);  //insserting at begin 
    // InsertAtEnd(head,tail,4);   //insertion at end

    // // InsertAtEnd(head,tail,55); 
    // // InsertAtEnd(head,tail,66); 
    // // InsertAtEnd(head,tail,77); 
    // printLL(head);  // printing LL




   /* THIS WAS A TYPE TO MAKE LINKED LIST N PERFORM OPERATIONS*/

//    BETTER WAY 


// Node* head=NULL;
// Node* tail=NULL;

// InsertAtBegin(head,tail,5);
// InsertAtBegin(head,tail,4);
// InsertAtBegin(head,tail,3);

// InsertAtEnd(head,tail,7);
// InsertAtMid(head,tail,101,3);

// InsertAtMid2(head,tail,202,4);
// printLL(head);

// InsertAtBegin(head,tail,5);
// InsertAtBegin(head,tail,4);
// InsertAtBegin(head,tail,3);
// InsertAtBegin(head,tail,2);
// InsertAtBegin(head,tail,1);
// printLL(head);


// deleteNode(head,tail,1);
// printLL(head);





// FREE TO USE METHOD
Node* head=NULL;
Node* tail=NULL;

int op;
int d;
int p;
while(1){
    cout<<"Enter operation you want to perform"<<endl;
    cout<<" 1.Insert at begin \n 2.Insert at end \n 3.Insert At position \n 4.Delete Node \n 5.Display List \n 6.Stop"<<endl;
    cin>>op;

    switch(op){
        case 1:
        cout<<"Enter Data : ";
        cin>>d;
        cout<<endl;
        InsertAtBegin(head,tail,d);
        break;

        case 2:
        cout<<"Enter Data : ";
        cin>>d;
        cout<<endl;
        InsertAtEnd(head,tail,d);
        break;

        case 3:
        cout<<"Enter Data : ";
        cin>>d;
        cout<<endl;
        cout<<"Enter Position : ";
        cin>>p;
        cout<<endl;
        InsertAtMid(head,tail,d,p);
        break;

        case 4:
        cout<<"Enter Position : ";
        cin>>p;
        cout<<endl;
        deleteNode(head,tail,p);
        break;

        case 5:
        printLL(head);
        break;

        case 6:
        exit(0);

        default:
        cout<<"Plz enter Valid Operation"<<endl;
        break;
    }
}
}
