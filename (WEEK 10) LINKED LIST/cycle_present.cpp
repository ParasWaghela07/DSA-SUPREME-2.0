/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 BAD WAY
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;
        ListNode* temp=head;
        while(temp){
            if(mp[temp]){
                return true;
            }
            mp[temp]=true;
            temp=temp->next;
        }

        return false;
    }
};

GOOD WAY
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast){
            fast=fast->next;
            // if(slow==fast) return true;
            if(fast){
                fast=fast->next;
                // if(slow==fast) return true;
                slow=slow->next;
                if(slow==fast) return true;
            }
        }

        return false;
    }
};