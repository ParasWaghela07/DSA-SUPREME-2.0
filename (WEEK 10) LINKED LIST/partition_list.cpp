/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
---NEW LIST---
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* head1=NULL;
        ListNode* head2=NULL;
        ListNode* tail1=NULL;
        ListNode* tail2=NULL;

        ListNode*temp=head;
        while(temp){
            ListNode* newnode=new ListNode(temp->val);
            if(temp->val<x){
                if(!head1) head1=newnode;

                if(!tail1) tail1=newnode;
                else tail1->next=newnode,tail1=newnode;
            }
            else{
                if(!head2) head2=newnode;

                if(!tail2) tail2=newnode;
                else tail2->next=newnode,tail2=newnode;
            }
            temp=temp->next;
        }

        if(tail1)tail1->next=head2;

        return head1 ? head1 :head2;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
--IN-PLACE--
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* head1=NULL;
        ListNode* head2=NULL;
        ListNode* tail1=NULL;
        ListNode* tail2=NULL;

        ListNode*temp=head;
        while(temp){
            if(temp->val<x){
                if(!head1) head1=temp;

                if(!tail1) tail1=temp;
                else tail1->next=temp,tail1=temp;
            }
            else{
                if(!head2) head2=temp;

                if(!tail2) tail2=temp;
                else tail2->next=temp,tail2=temp;
            }
            temp=temp->next;
            if(tail1) tail1->next=NULL;
            if(tail2) tail2->next=NULL;
        }

        if(tail1)tail1->next=head2;

        return head1 ? head1 :head2;
    }
};