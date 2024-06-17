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
    int getlen(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }

        if(getlen(head)<k){
            return head;
        }

        ListNode* prev=NULL;
        ListNode* curr=head;
        int posi=0;

        ListNode* nextnode=curr->next;

        while(posi<k){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
            posi++;
        }

        ListNode* recursionAns=NULL;
        if(nextnode!=NULL){
            recursionAns=reverseKGroup(nextnode,k);
            head->next=recursionAns; //DRY RUN KRO IMP / TRICKY

        }  

        return prev;


    }
};