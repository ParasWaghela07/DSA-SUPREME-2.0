 
 //SOLUTION 1
 
 ListNode* swapPairs(ListNode* head) {
       ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* pre = dummy;
        while(head && head->next){
            ListNode* first = head;
            ListNode* second = head->next;
            // swapin 
            // pre -> next = first->next;
            pre->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair
            pre = first;
            head = first->next;
        }
    return dummy->next;
 }


 //SOLUTION 2

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* prev=head;
        ListNode* curr=head->next;
        head=curr;
        ListNode* linker=NULL;

        while(curr!=NULL && curr->next!=NULL){

            prev->next=curr->next;
            curr->next=prev;

            if(linker!=NULL)
            linker->next=curr;

            linker=prev;

            prev=prev->next;
            curr=prev->next;
        }
            if(curr!=NULL){
            prev->next=curr->next;
            curr->next=prev;

            if(linker!=NULL)
            linker->next=curr;

            }
            
        return head;
    }
};