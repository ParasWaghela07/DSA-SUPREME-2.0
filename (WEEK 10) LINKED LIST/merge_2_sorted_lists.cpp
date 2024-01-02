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




//MY SOLUTION
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *t1=list1;
        ListNode *t2=list2;
        ListNode *curr=NULL;
        ListNode *newhead=NULL;

        if(list1==NULL){
            return list2;
        }

        if(list2==NULL){
            return list1;
        }

        if(t1->val < t2->val){
            newhead=t1;
            curr=t1;
            t1=t1->next;
        }
        else{
            newhead=t2;
            curr=t2;
            t2=t2->next;
        }

        while(t1!=NULL && t2!=NULL){
            
            if(t1->val < t2->val){
                curr->next=t1;
                curr=t1;
                t1=t1->next;
                curr->next=NULL;
            }
            else{
                curr->next=t2;
                curr=t2;
                t2=t2->next;
                curr->next=NULL;
            }
        }

        if(t2==NULL){
            while(t1!=NULL){
                curr->next=t1;
                curr=t1;
                t1=t1->next;
                curr->next=NULL;
            }
        }
        else if(t1==NULL){
            while(t2!=NULL){
                curr->next=t2;
                curr=t2;
                t2=t2->next;
                curr->next=NULL;
            }
        }
        return newhead;
    }
};


//LAKSHAY BHAIYA'S SOLUTION
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
        if(list1==NULL){
            return list2;
        }

        if(list2==NULL){
            return list1;
        }

        ListNode *ans=new ListNode(-1);
        ListNode *mptr=ans;

        while(list1 && list2){
            if(list1->val <= list2->val){
                mptr->next=list1;
                mptr=list1;
                list1=list1->next;
            }
            else{
                mptr->next=list2;
                mptr=list2;
                list2=list2->next;
            }
        }

        if(list1){
            mptr->next=list1;
        }
        if(list2){
            mptr->next=list2;
        }

        return ans->next; 



    }

