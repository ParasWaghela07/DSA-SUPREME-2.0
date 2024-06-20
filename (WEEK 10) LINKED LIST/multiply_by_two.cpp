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

-------ITERATIVE--------
class Solution {
public:
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

        return;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head) return NULL;

        rev(head);

        ListNode* it=head;
        int carry=0;

        while(it){
            int currValue=it->val;
            int currAns=(currValue*2) + carry;

            int digit=currAns%10;
            carry=currAns/10;

            it->val=digit;
            if(!it->next) break;

            it=it->next;
        }

        if(carry){
            ListNode* newNode=new ListNode(carry%10);
            it->next=newNode;
            it=newNode;
            carry=carry/10;
        }

        rev(head);

        return head;
    }
};


------------RECURSIVE--------

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
    void mul(ListNode* head,int &carry){
        if(!head) return;
        mul(head->next,carry);

        int prod = ( head->val * 2 ) + carry;
        int digit=prod%10;
        carry=prod/10;
        head->val=digit;
    }
    ListNode* doubleIt(ListNode* head) {
        if(!head) return NULL;

        int carry=0;

        mul(head,carry);

        if(carry){
            ListNode* newNode=new ListNode(carry);
            newNode->next=head;
            head=newNode;
        }

        return head;
    }
};