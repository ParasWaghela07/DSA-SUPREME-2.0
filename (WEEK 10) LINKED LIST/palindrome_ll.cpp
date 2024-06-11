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
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next){
            fast=fast->next;
            if(fast->next){
                fast=fast->next;
                slow=slow->next;
            }
        }

        return slow;
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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;

        ListNode* mid=getMid(head);
        ListNode* temp=mid->next;
        mid->next=NULL;
        mid=temp;
        rev(mid);
        
        ListNode* head1=head;
        ListNode* head2=mid;

        while(head1 && head2){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }

        return true;
    }
};