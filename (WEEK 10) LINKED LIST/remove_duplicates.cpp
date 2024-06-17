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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp=head;
        while(temp->next){
            ListNode* nxt=temp->next;
            if(temp->val==nxt->val){
                ListNode* nxtTonxt=nxt->next;
                temp->next=nxtTonxt;
                nxt->next=NULL;
                delete nxt;
            }
            else{
                temp=temp->next;
            }
        }

        return head;
    }
};