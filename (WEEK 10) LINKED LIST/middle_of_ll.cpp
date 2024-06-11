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
    ListNode* middleNode(ListNode* head) {

        if(!head) return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next){
            slow=slow->next;
            fast=fast->next; --------> APPROACH 1
            if(fast->next){
                fast=fast->next;
            }
        }

        while(fast){
            fast=fast->next;
            if(fast){
                fast=fast->next; --------> APPROACH 2
                slow=slow->next;
            }
        }

        while(fast->next){
            fast=fast->next;
            if(fast->next){
                fast=fast->next; --------> APPROACH 3 ( FOR MIDDLE NODE IS PREV IN EVEN LENGTH)
                slow=slow->next;
            }
        }

        return slow;
    }
};