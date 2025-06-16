#include<bits/stdc++.h>
using namespace std;

class Mylist{
    public:
    int val;
    int size;
    Mylist*next;

    Mylist(int data){
        this->val=data;
        this->next=NULL;
        this->size=1;
    }

};

    void insertatend(Mylist*&head ,int data){
        if(!head->next){
            Mylist*newnode=new Mylist(data);
            head->next=newnode;
        }
        else{
            Mylist*node=head;
            while(node->next) node=node->next;

            Mylist*newnode=new Mylist(data);
            node->next=newnode;
        }
        head->size++;
    }

    void insertatstart(Mylist*&head,int data){
        Mylist*node=new Mylist(data);
        node->next=head;
        node->size=head->size;
        head=node;
        head->size++;
    }

    void insertatpos(Mylist*&head,int data,int pos){
        if(pos<=1){
            insertatstart(head, data);
        }
        else if(pos>head->size){
            insertatend(head, data);
        }
        else{
            Mylist*prev=NULL;
            Mylist*curr=head;

            while(pos>1){
                prev=curr;
                curr=curr->next;
                pos--;
            }

            Mylist*newnode=new Mylist(data);
            prev->next=newnode;
            newnode->next=curr;
        }

        head->size++;
    }

    void printLL(Mylist*head){
        Mylist*it=head;
        while(it){
            cout<<it->val<<" ";
            it=it->next;
        }
    }


    void delfromstart(Mylist*&head){
        if(!head->next){
            cout<<"Cannot delete ,head is the only one remaining"<<endl;
            return;
        }
        else{
            head->next->size=head->size-1;
            Mylist*temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }

    void delfromend(Mylist*&head){
        if(!head->next){
            cout<<"Cannot delete ,head is the only one remaining"<<endl;
            return;
        }
        else{
            Mylist*prev=NULL;
            Mylist*curr=head;

            while(curr->next){
                prev=curr;
                curr=curr->next;
            }

            prev->next=NULL;
            delete curr;
            head->size--;
        }
    }

    void delfrompos(Mylist*&head,int pos){
        if(pos<=1){
            delfromstart(head);
        }
        else if(pos>head->size) delfromend(head);
        else{
            Mylist*prev=NULL;
            Mylist*curr=head;

            while(pos>1){
                prev=curr;
                curr=curr->next;
                pos--;
            }

            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
            head->size--;
        }
    }


int main(){
    Mylist*head=new Mylist(10);
    insertatend(head, 20);
    insertatend(head, 30);
    insertatstart(head, 5);
    insertatpos(head, 15, 3);
    
    printLL(head); // Output: 5 10 15 20 30
    cout << "\nSize of list: " << head->size << endl; // Output: Size of list: 5

    delfromstart(head);
    printLL(head); // Output: 10 15 20 30
    cout << "\nSize of list after deletion from start: " << head->size << endl; // Output: Size of list after deletion from start: 4
    delfromend(head);
    printLL(head); // Output: 10 15 20
    cout << "\nSize of list after deletion from end: " << head->size << endl; // Output: Size of list after deletion from end: 3
    delfrompos(head, 2);
    printLL(head); // Output: 10 20

    return 0;
}