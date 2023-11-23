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
class Solution {
public:

ListNode* findMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

 ListNode* merge(ListNode* list1, ListNode* list2) {
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
                // curr->next=NULL;
            }
            else{
                curr->next=t2;
                curr=t2;
                t2=t2->next;
                // curr->next=NULL;
            }
        }

        if(t2==NULL){
            while(t1!=NULL){
                curr->next=t1;
                curr=t1;
                t1=t1->next;
                // curr->next=NULL;
            }
        }
        else if(t1==NULL){
            while(t2!=NULL){
                curr->next=t2;
                curr=t2;
                t2=t2->next;
                // curr->next=NULL;
            }
        }
        return newhead;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        //sort RECURSIVELY
        left=sortList(left);
        right=sortList(right);

        //merge both left amd right lists
        ListNode* mergedList=merge(left,right);
        return mergedList;
    }
};