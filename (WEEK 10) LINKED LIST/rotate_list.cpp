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
        int count=0;
        while(head){
            count++;
            head=head->next;
        }

        return count;
    }

    void rev(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        head=prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(!head->next) return head;

        int len=getlen(head);
        int actK=k%len;

        if(actK==0) return head;

        int posi=len-actK;
        ListNode* temp=head;
        while(posi>1){
            temp=temp->next;
            posi--;
        }

        ListNode* saved=temp->next;
        ListNode* newHead=saved;
        temp->next=NULL;
        while(saved->next){
            saved=saved->next;
        }

        saved->next=head;

        return newHead;

        // rev(head);

        // int posi=actK;
        // ListNode* temp=head;
        // while(posi>1){
        //     temp=temp->next;
        //     posi--;
        // }
        // ListNode* list1=head;
        // ListNode* list2=temp->next;
        // temp->next=NULL;

        // rev(list1);
        // rev(list2);

        // temp=list1;
        // while(temp->next){
        //     temp=temp->next;
        // }

        // temp->next=list2;

        // return head=list1;
    }
};


//LAKSHAY BHAIYA'S SOLUTION

        if(head==NULL || head->next==NULL){
            return head;
        }

        if(k%getlen(head)==0){
            return head;
        }

        int newTailPos=getlen(head)-k%getlen(head)-1;
        ListNode* tail=head;

        for(int i=0;i<newTailPos;i++){
            tail=tail->next;
        }

        ListNode* newhead=tail->next;
        tail->next=NULL;

        ListNode* it=newhead;
        while(it->next!=NULL){
            it=it->next;
        }

        it->next=head;

        return newhead;