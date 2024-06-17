/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * 
 */

----------MINE ---------
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp1=head;
        ListNode* temp2=head->next;
        ListNode* list2=head->next;

        while(temp1 && temp2){
            ListNode* nextOddNode=temp2->next;
            temp1->next=nextOddNode;
            temp1=nextOddNode;

            if(!temp1) break;
            
            ListNode* nextEvenNode=temp1->next;
            temp2->next=nextEvenNode;
            temp2=nextEvenNode;
        }

        ListNode* temp=head;

        while(temp->next){
            temp=temp->next;
        }
        temp->next=list2;

        return head;
    }
};

------LAKSHAY BHAIYA--------

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* h1=head;
        ListNode* h2=head->next;

        ListNode* evenHead=h2;

        while(h2 && h2->next){
            h1->next=h2->next;
            h2->next=h2->next->next;

            h1=h1->next;
            h2=h2->next;
        }

        h1->next=evenHead;

        return head;
    }
};