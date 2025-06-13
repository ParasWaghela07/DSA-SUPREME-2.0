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
    void rev(ListNode* &head){
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr){
            ListNode*nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head=prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;

        ListNode*x=head;
        ListNode*dummy=new ListNode(-1);
        ListNode*prevTail=NULL;

        while(x){
            ListNode*currhead=x;
            ListNode*tail=currhead;

            for(int i=0;i<k-1 && x!=NULL;i++){
                x=x->next;
            }
            if(!x) break;

            ListNode*nxt=x->next;
            x->next=NULL;
            rev(currhead);
            if(!dummy->next) dummy->next=currhead;

            if(prevTail)prevTail->next=currhead;
            tail->next=nxt;
            prevTail=tail;
            x=nxt;
        }

        return dummy->next;
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