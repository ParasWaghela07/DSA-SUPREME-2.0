//MY SOLUTION

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        if(k%getlen(head)==0){
            return head;
        }

        k=k%getlen(head);

        while(k){
            ListNode* prev=NULL;
            ListNode* curr=head;

            while(curr->next!=NULL){
                prev=curr;
                curr=curr->next;
            }

            ListNode* newHead=new ListNode(curr->val);
            newHead->next=head;
            head=newHead;
            prev->next=NULL;
            delete curr;

            k--;
        }
        return head;
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