#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void reverse(ListNode* &head2){
    if(head2==NULL){
        return;
    }

    ListNode* prev=NULL;
    ListNode* curr=head2;

    while(curr!=NULL){
        ListNode* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }

    head2=prev;

    return;
}
    // void reorderList(ListNode* head) {
        
    //     if(head->next==NULL){
    //         return;
    //     }

    //     ListNode* fast = head->next->next;
    //     ListNode* slow = head;
    //     while(fast && fast->next!=NULL) {
    //         fast = fast->next->next;
    //         slow = slow->next;
    //     }

    //     ListNode* head2=slow->next;
    //     slow->next=NULL;

    //     reverse(head2);

    //     ListNode* newHead=head;

    //     ListNode* temp1=head;
    //     ListNode* temp2=head2;

    //     while(temp1!=NULL && temp2!=NULL){

    //         temp1=temp1->next;
    //         temp2=temp2->next;
    //         head->next=head2;
    //         head2->next=temp1;

    //         head=temp1;
    //         head2=temp2;
    //     }

    //     head=newHead;

    void printLL(ListNode* head){
        ListNode* temp=head;

        while(temp!=NULL){
            cout<<temp->val<<" ";     
            temp=temp->next;   
            }
    }
    // }

    int main(){

        ListNode* start=new ListNode(1);
        ListNode* start1=new ListNode(2);
        ListNode* start2=new ListNode(3);

        start->next=start1;
        start1->next=start2;
        start2->next=NULL;

        ListNode* head=start;

        reverse(head);

        printLL(head);



    }